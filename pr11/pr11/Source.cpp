#include <iostream>
#include <locale>
#include <string>
#include <windows.h>
#include "DoubleHash.h"
using namespace std;

void menu_0();
void choice_0();
void menu_1(double_hash* table);
void choice_1(double_hash* table);

void menu_0()
{
	cout << "Структура элемента множества: Владелец телефона (номер телефона, адрес)\n"
		<< "Ключ записей: Последовательность символов\n"
		<< "Метод хеширования: Открытая адресация (двойное хеширование)\n\n"
		<< "------------------ Начальное меню ------------------\n"
		<< "[1] - Начало работы\n"
		<< "[0] - Завершить работу программы\n"
		<< "------ Введите номер команды для ее выполнения ------\n";
	choice_0();
}
void choice_0()
{
	int choice;
	int size;
	cin >> choice;
	switch (choice)
	{
	default:
	{
		cout << "Ошибка. Такого номера не существует.\n";
		system("pause");
		system("cls");
		choice_0();
		break;
	}
	case 1:
	{
		system("cls");
		cout << "Введите размер таблицы\n";
		cin >> size;
		while (size < 1 || size > 255)
		{
			system("cls");
			cout << "В таблице не может быть 0 или более 255 элементов. Повторите ввод\n";
				cin >> size;

		}
		double_hash table(size);
		system("cls");
		menu_1(&table);
		break;
	}
	case 0:
	{
		system("cls");
		cout << "Завершение работы\n";
		break;
	}
	}
}
void menu_1(double_hash* table)
{
	cout << "Структура элемента множества: Владелец телефона (номер телефона, адрес)\n"
		<< "Ключ записей: Последовательность символов\n"
		<< "Метод хеширования: Открытая адресация (двойное хеширование)\n\n"
		<< "-------- Меню команд для работы программы --------\n"
		<< "[1] - Вставка элемента\n"
		<< "[2] - Удаление элемента по ключу\n"
		<< "[3] - Поиск элемента по ключу\n"
		<< "[4] - Вывод таблицы\n"
		<< "[5] - Вернуться\n"
		<< "----- Введите номер команды для ее выполнения -----\n";
	choice_1(table);
}
void choice_1(double_hash* table)
{
	int choice;
	string address;
	int number;
	cin >> choice;
	switch (choice)
	{
	default:
	{
		cout << "Ошибка. Такого номера не существует.\n";
		system("pause");
		system("cls");
		choice_1(table);
		break;
	}
	case 1: //Вставка
	{
		system("cls");
		if (table->full())
			cout << "Таблица заполнена\n";
		else
		{
			cout << "Введите номер телефона и адрес: ";
			cin >> number >> address;
			table->insert_item(number, address);
		}
		cout << "Таблица (Индекс-->Номер телефона-->Адрес)\n";
		table->output_table();
		system("pause");
		system("cls");
		menu_1(table);
		break;
	}

	case 2:
	{
		system("cls");
		if (table->empty())
			cout << "Таблица пуста\n";
		else
		{
			cout << "Введите ключ удаляемого элемента\n";
			cin >> number;
			table->delete_item(number);
		}
		cout << "Таблица (Индекс-->Номер телефона-->Адрес)\n";
		table->output_table();
		system("pause");
		system("cls");
		menu_1(table);
		break;
	}
	case 3:
	{
		system("cls");
		if (table->empty())
			cout << "Таблица пуста\n";
		else
		{
			cout << "Введите ключ искомого элемента\n";
			cin >> number;
			table->search(number);
		}
		cout << "Таблица (Индекс-->Номер телефона-->Адрес)\n";
		table->output_table();
		system("pause");
		system("cls");
		menu_1(table);
		break;
	}
	case 4:
	{
		system("cls");
		cout << "Таблица (Индекс-->Номер телефона-->Адрес)\n";
		table->output_table();
		system("pause");
		system("cls");
		menu_1(table);
		break;
	}
	case 0:
	{
		system("cls");
		menu_0();
		return;
	}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu_0();
}