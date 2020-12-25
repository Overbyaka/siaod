#include <iostream>
#include <vector>
using namespace std;

class Equation {
private:
	vector<vector<int>> mult; // Количество скалярных умножений
	vector<vector<int>> brackets; // Расстановка скобок
	vector<int> matrixes; // Уравнение без скобок
	string equation; // Уравнение со скобками
public:
	Equation() {
		int size, temp;
		cout << "Введите кол-во матриц:" << endl;
		cin >> size;
		cout << endl << "Введите последовательность матриц:" << endl;
		for (int i = 0; i < size; i++) {
			cin >> temp;
			matrixes.push_back(temp);
		}
	}
	void getOrder() {
		int n = matrixes.size() - 1;
		for (int i = 0; i < n; i++) {
			mult.push_back(vector <int>());
			brackets.push_back(vector <int>());
			// Заполнение матриц 0
			for (int a = 0; a < n; a++) {
				mult[i].push_back(0);

				brackets[i].push_back(0);
			}
		}
		int j;
		// Алгоритм поиска минимального количества скалярных умножений
		for (int l = 1; l < n; l++) {
			for (int i = 0; i < n - l; i++) {
				j = i + l;
				mult[i][j] = 2147483647;
				for (int k = i; k < j; k++) {
					int q = mult[i][k] + mult[k + 1][j] +

						matrixes[i] * matrixes[k + 1] * matrixes[j + 1];
					if (q < mult[i][j]) {
						mult[i][j] = q;
						brackets[i][j] = k;
					}
				}
			}
		}
		out(0, n - 1, 0);
		cout << endl << "Оптимальный порядок: " << equation << endl;
	}

	// Создание уравнения со скобками
	void out(int i, int j, int flag) {
		if (i == j) {
			equation += "A";
		}
		else {
			if (flag != 0)
				equation += "(";
			out(i, brackets[i][j], 1);
			equation += "*";
			out(brackets[i][j] + 1, j, 1);

			if (flag != 0)
				equation += ")";

		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Equation ds;
	ds.getOrder();
}