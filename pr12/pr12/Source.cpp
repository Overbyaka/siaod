#include <iostream>
#include "FileWork.h"
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "������� ������ �����: ";
	cin >> n;
	create_file(n);
	load_binFile();
	cout << "\"��������������\" �������� ����: " << endl;
	cout << read_binFile();
	cout << "���������� ��������� �����: " << endl;
	print_binFile();
	bool pr = true;
	while (pr) {
		cout << "�������� ��������: " << endl;
		cout << "[1] - ����� �����" << endl;
		cout << "[2] - �������� �����" << endl;
		cout << "[0] - ����� �� ���������" << endl;
		cout << "[ ] - ";
		cin >> n;
		switch (n) {
		case 1:
			cout << "������� �����, �� ������� ������ ���������� ������ ������� ����� : ";
				cin >> n;
			create_people(n);
			print_people();
			break;
		case 2:
			cout << "������� �����, �� ������� ������ ���������� ������ ��������� ����� : ";
				cin >> n;
			remove(n);
			cout << read_binFile();
			break;
		case 0:
			cout << "����� �� ��������� ?" << endl;

			cout << "[1] - ��" << endl;
			cout << "[2] - ���" << endl;
			cout << "[ ] - ";
			cin >> n;
			switch (n) {
			case 1:
				pr = false;
				break;
			}
		}
		cout << "-------------------" << endl;
	}
	remove(n);
	cout << read_binFile();
	return 0;
}