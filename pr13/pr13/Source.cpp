#include <iostream>
#include <cstring>
using namespace std;
void vivod(int V, int** G, bool* selected, bool pr) {
	if (pr) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cout << G[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "Вершина 1 -> Вершина 2" << " : " << "Вес вершин";
	}
	for (int i = 0; i < V; i++)
		selected[i] = false;
	int count;
	count = 0;
	selected[0] = true;
	int x;
	int y;
	cout << endl;
	while (count < V - 1) {
		int min = 99999;
		x = 0;
		y = 0;
		for (int i = 0; i < V; i++) {
			if (selected[i]) {
				for (int j = 0; j < V; j++) {
					if (!selected[j] && G[i][j]) {
						if (min > G[i][j]) {
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		cout << x + 1 << " -> " << y + 1 << " : " << G[x][y];
		cout << endl;
		selected[y] = true;
		count++;
	}
}
int main() {
	setlocale(LC_ALL, "Rus");
	int V = 7;
	int S[7][7] = {
	{0, 20, 0, 0, 0, 23, 1},
	{20, 0, 15, 0, 0, 0, 4},
	{0, 15, 0, 3, 0, 0, 9},

	{0, 0, 3, 0, 17, 0, 16},
	{0, 0, 0, 17, 0, 28, 25},
	{23, 0, 0, 0, 28, 0, 36},
	{1, 4, 9, 16, 25, 36, 0}
	};
	int** G;
	int n;
	bool* selected;
	cout << "Начальный граф: " << endl;
	G = new int* [V];
	for (int i = 0; i < V; i++)
		G[i] = new int[V];
	selected = new bool[V];
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			G[i][j] = S[i][j];
		}
	}
	vivod(V, G, selected, true);
	cout << "-----------------------------------------------------------------" <<
		endl;
	cout << "Создать новый граф?" << endl;
	cout << "[1] - Создать" << endl;
	cout << "[0] - Выход из программы" << endl;
	cout << "[ ] - ";
	cin >> n;
	bool pr = true;
	switch (n) {
	case 1:
		cout << "Введите количество вершин в графе: ";
		cin >> V;
		G = new int* [V];
		for (int i = 0; i < V; i++)
			G[i] = new int[V];
		selected = new bool[V];
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				G[i][j] = 0;
			}
		}
		while (pr) {
			cout << "Выберите действие: " << endl;
			cout << "[1] - Добавить связь" << endl;
			cout << "[2] - Вывод графа" << endl;
			cout << "[3] - Вывод результата работы алгоритма Прима" <<
				endl;
			cout << "[0] - Выход из программы" << endl;
			cout << "[ ] - ";
			cin >> n;
			switch (n) {
			case 1:

				int first, last, weight_1;
				cout << "Введите номер одной вершины: ";
				cin >> first;
				cout << "Введите номер другой вершины: ";
				cin >> last;
				cout << "Введите вес: ";
				cin >> weight_1;
				G[first - 1][last - 1] = weight_1;
				G[last - 1][first - 1] = weight_1;
				break;
			case 2:
				for (int i = 0; i < V; i++) {
					for (int j = 0; j < V; j++) {

						cout << G[i][j] << " ";
					}
					cout << endl;
				}
				break;
			case 3:
				vivod(V, G, selected, false);
				break;
			case 0:
				return 0;
			}
			cout << "-----------------------------------------------------------------" << endl;
		}
		break;
	case 2:
		return 0;
	}
	return 0;
}