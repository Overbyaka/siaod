#pragma once
#include <string>

using namespace std;
class double_hash
{
	int cur_size, max_size, index;
	int* key;
	string* address;
public:
	double_hash(int max);
	~double_hash();
	bool full();
	bool empty();
	void insert_item(int number, string address);
	void delete_item(int number);
	void output_table();
	void search(int number);
};