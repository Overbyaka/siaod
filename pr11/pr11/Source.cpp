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
	cout << "��������� �������� ���������: �������� �������� (����� ��������, �����)\n"
		<< "���� �������: ������������������ ��������\n"
		<< "����� �����������: �������� ��������� (������� �����������)\n\n"
		<< "------------------ ��������� ���� ------------------\n"
		<< "[1] - ������ ������\n"
		<< "[0] - ��������� ������ ���������\n"
		<< "------ ������� ����� ������� ��� �� ���������� ------\n";
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
		cout << "������. ������ ������ �� ����������.\n";
		system("pause");
		system("cls");
		choice_0();
		break;
	}
	case 1:
	{
		system("cls");
		cout << "������� ������ �������\n";
		cin >> size;
		while (size < 1 || size > 255)
		{
			system("cls");
			cout << "� ������� �� ����� ���� 0 ��� ����� 255 ���������. ��������� ����\n";
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
		cout << "���������� ������\n";
		break;
	}
	}
}
void menu_1(double_hash* table)
{
	cout << "��������� �������� ���������: �������� �������� (����� ��������, �����)\n"
		<< "���� �������: ������������������ ��������\n"
		<< "����� �����������: �������� ��������� (������� �����������)\n\n"
		<< "-------- ���� ������ ��� ������ ��������� --------\n"
		<< "[1] - ������� ��������\n"
		<< "[2] - �������� �������� �� �����\n"
		<< "[3] - ����� �������� �� �����\n"
		<< "[4] - ����� �������\n"
		<< "[5] - ���������\n"
		<< "----- ������� ����� ������� ��� �� ���������� -----\n";
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
		cout << "������. ������ ������ �� ����������.\n";
		system("pause");
		system("cls");
		choice_1(table);
		break;
	}
	case 1: //�������
	{
		system("cls");
		if (table->full())
			cout << "������� ���������\n";
		else
		{
			cout << "������� ����� �������� � �����: ";
			cin >> number >> address;
			table->insert_item(number, address);
		}
		cout << "������� (������-->����� ��������-->�����)\n";
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
			cout << "������� �����\n";
		else
		{
			cout << "������� ���� ���������� ��������\n";
			cin >> number;
			table->delete_item(number);
		}
		cout << "������� (������-->����� ��������-->�����)\n";
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
			cout << "������� �����\n";
		else
		{
			cout << "������� ���� �������� ��������\n";
			cin >> number;
			table->search(number);
		}
		cout << "������� (������-->����� ��������-->�����)\n";
		table->output_table();
		system("pause");
		system("cls");
		menu_1(table);
		break;
	}
	case 4:
	{
		system("cls");
		cout << "������� (������-->����� ��������-->�����)\n";
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