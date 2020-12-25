#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void create_file(int n);
void write(string text);
void load_binFile();
string decode(string hex_str);
string read_binFile();
void print_binFile();
void print_people();
void create_people(int n);
void remove(int n);