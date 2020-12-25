#include <iostream>
#include "FileWork.h"
void create_file(int n) {
	string cities[] = {
	"Bryansk","Moscow","Sanct-Peterburg","Kazan","Samara","Kiev","Minsk","Kursk" };
	string fam[] = {
	"Grishkova","Ivanov","Popova","Fedorov","Mur","Leinova","Petrov","Volkova" };
	ofstream test_file("text.txt");
	for (int i = 0; i < n; i++) {
		string number = "89";
		for (int j = 0; j < 9; j++) {
			int numb = rand() % 10;
			number += to_string(numb);
		}
		test_file << number << " " + cities[rand() % 8] << " "
			<< fam[rand() % 8] << '\n';
	}
	test_file.close();
}
void write(string text) {
	ofstream file("binary.txt", ios_base::binary | ios_base::trunc);
	for (int i = 0; i < text.size(); i++) {
		if (text[i] != int('\n')) {
			file << hex << (int)(text[i]);
			file << " ";
		}
		else
			file << "\n";
	}
	file.close();

}
void load_binFile() {
	string text, temp;
	ifstream test_file("text.txt");
	while (getline(test_file, temp, '\n')) {
		text += temp + '\n';
	}
	write(text);
	test_file.close();
}
string decode(string hex_str) {
	stringstream ss;
	string word;
	istringstream iss(hex_str);
	int n;
	while (iss >> word) {
		char* end;
		n = strtol(word.c_str(), &end, 16);
		ss << char(n);
	}
	return ss.str();
}
string read_binFile() {
	ifstream binFile("binary.txt");
	string temp;
	stringstream ss;
	int n;
	while (getline(binFile, temp, '\n')) {
		ss << decode(temp) << '\n';
	}
	binFile.close();
	return ss.str();
}
void print_binFile() {
	ifstream binFile("binary.txt");
	string temp;
	while (getline(binFile, temp, '\n')) {
		cout << temp << endl;
	}
	binFile.close();
}
void print_people() {
	ifstream pFile("people.txt");
	string temp;
	while (getline(pFile, temp, '\n')) {
		cout << temp << endl;
	}
	pFile.close();
}
void create_people(int n) {
	ifstream binFile("binary.txt");
	ofstream people("people.txt", ios_base::trunc);
	string temp, word;
	while (getline(binFile, temp, '\n')) {
		string text = decode(temp);
		istringstream iss(text);
		iss >> word;
		int N = atoi(word.substr(0, int(log10(n) + 1)).c_str());
		if (n == N) {
			iss >> word;
			iss >> word;
			people << word + "\n";
		}

	}
	binFile.close();
	people.close();
}
void remove(int n) {
	ifstream binFile1("binary.txt");
	vector<string> strings;
	string temp, word;
	while (getline(binFile1, temp, '\n')) {
		strings.push_back(temp);
		temp = decode(temp);
		istringstream iss(temp);
		iss >> word;
		if (atoi(word.substr(0, int(log10(n) + 1)).c_str()) == n) {
			strings.pop_back();
		}
	}
	binFile1.close();
	ofstream binFile2("binary.txt");
	for (int i = 0; i < strings.size(); i++) {
		binFile2 << strings[i] + "\n";
	}
	binFile2.close();
}