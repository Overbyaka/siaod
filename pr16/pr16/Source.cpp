#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
#define underline "\033[4m"
#define back "\033[0m"
class Task {
public:
	Task(vector<vector<double>> temp) {
		int tmp = temp.size() + temp[0].size();
		for (int i = 0; i < temp.size(); i++) {
			table.push_back(vector<double>());
			for (int j = 0; j < tmp; j++) {
				if (j < temp[0].size())
					table[i].push_back(temp[i][j]);
				else
					table[i].push_back(0);
			}
			if ((temp[0].size() + i) <= table[0].size()) {
				table[i][temp[0].size() + i] = 1;
			}
		}
	}
	void comp(string eq) {
		while (isNegative()) {
			int indLine = findLine();
			if (check(indLine)) {
				int indColumn = findColumn(indLine), num =
					table[indLine][indColumn];
				for (int i = 0; i < table[indLine].size(); i++) {
					table[indLine][i] /= num;
				}
				for (int i = 0; i < table.size(); i++) {
					if (indLine != i) {
						int t_num = table[i][indColumn];
						for (int j = 0; j < table[0].size(); j++) {
							table[i][j] -= table[indLine][j] * t_num;
						}
					}
				}
			}
			else {
				out(indLine, eq);
				return;
			}
		}
		solvable();
	}
private:
	vector<vector<double>> table;
	bool isNegative() {
		for (int i = 0; i < table.size(); i++) {
			if (table[i][0] < 0) {
				return true;
			}

		}
		return false;
	}
	int findLine() {
		double temp = 0, ind = 0;
		for (int i = 0; i < table.size(); i++) {
			if (table[i][0] < 0)
				if (abs(table[i][0]) > temp) {
					temp = abs(table[i][0]);
					ind = i;
				}
		}
		return ind;
	}
	bool check(int line) {
		bool flag = false;
		for (int i = 1; i < table.size(); i++) {
			if (table[line][i] < 0) {
				flag = true;
			}
		}
		return flag;
	}
	int findColumn(int line) {
		double temp = 0, ind = 0;
		for (int i = 1; i < table.size(); i++) {
			if (table[line][i] < 0)
				if (abs(table[line][i]) > temp) {
					temp = abs(table[line][i]);
					ind = i;
				}
		}
		return ind;
	}
	void out(int ind, string eq) {
		cout << "Для уравнения " << eq << ", при заданных условиях, решений нет" <<
			endl << endl;
		cout << "Доказательство:" << endl;
		cout << "В столбце b присутствуют отрицательные значения." << endl;
		cout << "Максимальное по модулю отрицательное значение находится в строке: " << ind+1 << endl;
			cout << "Так как в этой строке нет отрицательных значений, то решения задачи не существует." << endl;
			cout << endl << "Симплекс-таблица:" << endl;
		cout << underline << " ";
		for (int j = 0; j < table[0].size() - 1; j++) {
			cout << setw(9) << "x" << j + 1;
		}
		cout << setw(10) << "b" << back;
		for (int i = 0; i < table.size(); i++) {
			cout << endl << i + 1 << "|";
			for (int j = 1; j < table[0].size(); j++) {
				if (table[i][j] == -0)
					table[i][j] = 0;
				cout << setw(10) << table[i][j];
			}
			cout << setw(10) << table[i][0] << endl;
		}
	}
	void solvable() {
		cout << "Эту задачу можно решить";
	}
};
int main() {
	setlocale(LC_ALL, "Russian");

	string eq = " 3x1 - 2x2";
	vector<vector<double>> lim = { {2, 1, 1}, {-10, -2, -2}, {0, -1, 0}, {0, 0, -1} };
	Task task(lim);
	task.comp(eq);
}