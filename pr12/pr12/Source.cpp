#include <iostream>
#include "FileWork.h"
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите размер файла: ";
	cin >> n;
	create_file(n);
	load_binFile();
	cout << "\"Расшифрованный\" бинарный файл: " << endl;
	cout << read_binFile();
	cout << "Содержимое бинарного файла: " << endl;
	print_binFile();
	bool pr = true;
	while (pr) {
		cout << "Выберите действие: " << endl;
		cout << "[1] - Поиск людей" << endl;
		cout << "[2] - Удаление людей" << endl;
		cout << "[0] - Выход из программы" << endl;
		cout << "[ ] - ";
		cin >> n;
		switch (n) {
		case 1:
			cout << "Введите число, на которое должны начинаться номера искомых людей : ";
				cin >> n;
			create_people(n);
			print_people();
			break;
		case 2:
			cout << "Введите число, на которое должны начинаться номера удаляемых людей : ";
				cin >> n;
			remove(n);
			cout << read_binFile();
			break;
		case 0:
			cout << "Выйти из программы ?" << endl;

			cout << "[1] - Да" << endl;
			cout << "[2] - Нет" << endl;
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