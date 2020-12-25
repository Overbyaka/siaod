#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct alfa {
	char symb;
	int count;
	double freq;
	alfa* left;
	alfa* right;
	string code = "";
	alfa(char symb) {
		this->symb = symb;
		this->count = 1;
	}
	alfa(alfa* left, alfa* right) {
		this->symb = 0;
		this->left = left;
		this->right = right;
		this->freq = left->freq + right->freq;
		this->count = left->count + right->count;
	}
};
class Tree {
private:
	alfa* root;
	string str;
	vector<alfa*> N;
public:
	Tree() {
		input();
		make_tree();
		set_code(root);
	}
	void input() {
		getline(cin, str);
		bool flag;
		for (int i = 0; i < str.size(); ++i) {
			flag = false;
			for (int j = 0; j < N.size(); ++j) {
				if (N[j]->symb == str[i]) {
					N[j]->count++;
					flag = true;
				}
			}
			if (!flag) {
				N.push_back(new alfa(str[i]));
			}
		}
		for (int i = 0; i < N.size(); ++i) {
			N[i]->freq = (double)N[i]->count / str.size();
		}
		sort(N.begin(), N.end(), [](alfa* l1, alfa* l2)
			{return l1->freq > l2->freq; });

	}
	void make_tree() {
		double min = 2;
		int left, right;
		vector<alfa*> temp(N);
		while (temp.size() != 1) {
			min = 2;
			for (int i = temp.size() - 1; i >= 0; --i) {
				for (int j = i - 1; j >= 0; --j) {
					if (temp[i]->freq + temp[j]->freq < min) {
						min = temp[i]->freq + temp[j]->freq;
						left = j;
						right = i;
					}
				}
			}
			temp.push_back(new alfa(temp[left], temp[right]));
			temp.erase(temp.begin() + right);
			temp.erase(temp.begin() + left);
		}
		root = temp[0];
	}
	void set_code(alfa* letter) {
		if (letter->symb == 0) {
			letter->left->code = letter->code + '0';
			letter->right->code = letter->code + '1';
			set_code(letter->left);
			set_code(letter->right);
		}
		else return;
	}
	void out() {
		cout << endl << "No Символ Кол-во Код " << endl;
		for (int i = 0; i < N.size(); i++) {
			if (i < 9)
				cout << i + 1 << " " << N[i]->symb << " " << N[i]->count << " " << N[i]->code << endl;
			else
				cout << i + 1 << " " << N[i]->symb << " " << N[i] -> count << " " << N[i]->code << endl;
		}
		cout << endl << "Закодированная строка: " << endl;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < N.size(); j++) {
				if (str[i] == N[j]->symb) {
					cout << N[j]->code << ' ';
				}
			}
		}
		double l = 0;
		for (int i = 0; i < N.size(); i++) {
			l += N[i]->code.size();
		}
		l /= N.size();
		cout << endl << endl << "Средняя длина полученного кода " << l << endl;
		double disp = 0;
		for (int i = 0; i < str.size(); ++i) {
			for (int j = 0; j < N.size(); ++j) {
				if (str[i] == N[j]->symb) {
					disp += (N[j]->code.size() - l) *
						(N[j]->code.size() - l);
				}
			}
		}
		disp /= str.size();

		cout << "Дисперсия: " << disp << endl;
	}
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку для кодирования: ";
	int pr;
	Tree tree;
	tree.out();
	return 0;
}