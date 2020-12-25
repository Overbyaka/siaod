#include <iostream>
#include "DoubleHash.h"
using namespace std;
double_hash::double_hash(int size)
{
	cur_size = 0;
	max_size = size;
	index = 0;
	address = new string[max_size];
	key = new int[max_size];
	for (int i = 0; i < max_size; i++)
		key[i] = -1;
}
double_hash::~double_hash()
{
	delete[]key;
	delete[]address;
}
bool double_hash::full()
{
	return (cur_size == max_size) ? true : false;
}
bool double_hash::empty()
{
	return (cur_size == 0) ? true : false;
}
void double_hash::insert_item(int number, string address)
{
	for (int i = 0; i < max_size; i++) {
		if (key[i] == number && key[i] != -1) {

			cout << "Вызвана коллизия: '" << this->key[i] << " " << this -> address[i] << "' и '" << number << " " << address << "' " << endl;
			return;
		}
	}
	for (int i = 0; i < max_size; i++)
	{
		if (key[i] == -1) {
			key[i] = number;
			this->address[i] = address;
			cur_size++;
			cout << "Вставка произошла успешно" << endl;
			return;
		}
	}
	cout << "Ошибка" << endl;
}
void double_hash::delete_item(int number)
{
	for (int i = 0; i < max_size; i++)
	{
		if (key[i] == number)
		{
			key[i] = -1;
			address[i] = " ";
			cur_size--;
			return;
		}
	}
	cout << "Ключ '" << number << "' не найден\n";
}
void double_hash::output_table()
{
	for (int i = 0; i < max_size; i++)
	{
		cout << i + 1 << " --> ";
		if (key[i] != -1)
			cout << key[i] << " --> " << address[i];
		cout << endl;
	}
}
void double_hash::search(int number)
{
	for (int i = 0; i < max_size; i++)
	{
		if (key[i] == number)
		{
			cout << i + 1 << " --> " << address[i] << endl;
			return;
		}
	}
	cout << "Ключ '" << number << "' не найден\n";
}