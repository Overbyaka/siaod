#include <iostream>
#include <locale.h>

using namespace std;

struct list
{
	int value;
	int n; //Размерность очереди
	struct list* link;
};

struct list* initList(int n) // n- максимальное число узлов в очереди
{
	struct list* lst;
	lst = (struct list*)malloc(sizeof(struct list)); // выделение памяти под корень списка
	lst->n = n;
	lst->value = NULL;
	lst->link = NULL; // это последний узел списка
	return(lst);
}

int* initMas(int n)
{
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
		mas[i] = NULL;
	return mas;
}

bool isEmptyList(list* root)
{
	return (root->link == NULL && root->value == NULL);
}

bool isEmptyMas(int* mas)
{
	return mas[0] == NULL;
}

bool isFullList(list* root)
{
	struct list* temp = root;
	for (int i = 0; i < root->n; i++)
	{
		if (temp->link == NULL)
			return false;
		temp = temp->link;
	}
	return true;
}

bool isFullMas(int* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (mas[i] == NULL)
			return false;
	}
	return true;
}

void addElemList(list* root, int adding) //Добавление элемента в очередь
{
	struct list* temp1;
	temp1 = (struct list*)malloc(sizeof(list));
	struct list* temp = root;
	if (isFullList(root) == true)
	{
		cout << "Ошибка! Очередь переполнена!\n";
		return;
	}

	while (temp->value != NULL) //Проходимся по циклу, пока не дойдем до конца очереди
	{
		temp = temp->link;
	}

	temp->link = temp1;
	temp->value = adding;
	temp1->n = root->n;
	temp1->link = NULL;
	temp1->value = NULL;
	return;
}

void addElemMas(int* mas, int adding, int n)
{
	if (isFullMas(mas, n))
	{
		cout << "Ошибка! Очередь переполнена!\n";
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (mas[i] == NULL)
		{
			mas[i] = adding;
			return;
		}
	}
}

struct list* deletElemList(list* root) //Удаление элемента из очереди, возвращает новый корень очереди
{
	struct list* temp;
	if (isEmptyList(root))
	{
		cout << "Ошибка! Очередь пустая!\n";
		return root;
	}

	temp = root->link;
	free(root); // освобождение памяти текущего корня
	cout << "Элемент удален\n";
	return temp;
}

void deletElemMas(int* mas, int n)
{
	if (isEmptyMas(mas))
	{
		cout << "Ошибка! Очередь пустая!\n";
		return;
	}
	for (int i = 0; i < n-1; i++)
	{
		if (mas[i+1] == NULL)
		{
			mas[i] = NULL;
			return;
		}
		mas[i] = mas[i + 1];
	}
	mas[n - 1] = NULL;
}

int findElemList(int indexNumberFind, list* root)
{
	struct list* temp = root;
	for (int i = 0; i < indexNumberFind; i++)
	{
		temp = temp->link;
		if (temp == NULL)
			return NULL;
	}
	return temp->value;
}

int findElemMas(int indexNumberFind, int* mas, int n)
{
	if (indexNumberFind >= n)
		return NULL;
	return mas[indexNumberFind];
}

void listPrint(list* lst)
{
	struct list* temp = lst;
	while(temp->value!=NULL)
	{
		printf("%d\n", temp->value); // вывод значения элемента p
		temp = temp->link; // переход к следующему узлу
	} 
	cout << endl;
}

void masPrint(int* mas, int n)
{
	for (int i = 0; i < n && mas[i]!=NULL; i++)
	{
		printf("%d\n", mas[i]);
	}
	cout << endl;
}

void sortMas(int* mas, int n)
{
	if (mas[n - 1] == NULL) {
		cout << "Ошибка! Очередь не до конца заполнена!\n";
		return;
	}
	int max = 0, maxN = 0;
	int* mas1 = new int[n];
	int count = 0;
	for (int i = 0; i < n; i++)//Ищу максимальное число
	{
		if (mas[i] > max)
			max = mas[i];
	}
	while (max > 9)//Ищу количество разрядов в максимальном числе
	{
		max /= 10;
		maxN++;
	}
	for (int i = 0; i <= maxN; i++)
	{
		count = 0;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < n; k++)
			{
				int temp = (mas[k] / (int)pow(10, i));
				if (temp%10 == j) 
				{
					mas1[count] = mas[k];
					count++;
				}
			}
			
		}
		for (int k = 0; k < n; k++)
			mas[k] = mas1[k];
	}
	
	delete mas1;
}

void printMenu()
{
	cout << "---MENU---\n";
	cout << "[1]: Вставить элемент в очередь\n";
	cout << "[2]: Удалить элемент из очереди\n";
	cout << "[3]: Получить значение элемента очереди\n";
	cout << "[4]: Проверить, не пуста ли очередь\n";
	cout << "[5]: Проверить, не полни ли очередь\n";
	cout << "[6]: Вывести очередь\n";
	cout << "[7]: Выполнить сортировку (для списка недоступно)\n";
	cout << "[0]: Выход\n";
}

void printFirstMenu()
{
	cout << "Мы работаем с динамическим массивом или с однонаправленным динамическим списком?\n";
	cout << "[0]: Динамический массив\n";
	cout << "[1]: Однонаправленный динамический список\n";
}

bool start()
{
	int answer;
	printFirstMenu();
	cin >> answer;
	return answer;
}

void checkAnswerList(struct list* root)
{
	int answer;
	int a;
	char c;
	while (true)
	{
		cout << "Введите, что Вы хотите сделать: ";
		cin >> answer;
		switch (answer)
		{
		case 1:
			cout << "Введите какое значение вы хотите ввести: ";
			cin >> a;
			addElemList(root, a);
			break;
		case 2:
			root = deletElemList(root);
			break;
		case 3:
			cout << "Введите, какой элемент найти: ";
			cin >> a;
			a = findElemList(a, root);
			if (a)
				cout << "Данный элемент со значением " << a << endl;
			else
				cout << "Данный элемент не был найден в очереди!\n";
			break;
		case 4:
			if (isEmptyList(root))
			{
				cout << "Очередь пустая!\n";
			}
			else
			{
				cout << "Очередь непустая!\n";
			}
			break;
		case 5:
			if (isFullList(root))
			{
				cout << "Очередь полная!\n";
			}
			else
			{
				cout << "Очередь неполная!\n";
			}
			break;
		case 6:
			listPrint(root);
			break;
		case 0:
			cout << "Вы точно хотите выйти из программы? (Y/N)\n";
			cin >> c;
			if (c == 'Y')
			{
				while (root->link != NULL)
				{
					root = deletElemList(root);
				}
				free(root);
				return;
			}
			break;
		default:
			cout << "Вы ввели неверное число!\n";
			break;
		}
	}
}

void checkAnswerMas(int* mas, int n)
{
	int answer;
	int a;
	char c;
	while (true)
	{
		cout << "Введите, что Вы хотите сделать: ";
		cin >> answer;
		switch (answer)
		{
		case 1:
			cout << "Введите какое значение вы хотите ввести: ";
			cin >> a;
			addElemMas(mas, a, n);
			break;
		case 2:
			deletElemMas(mas, n);
			break;
		case 3:
			cout << "Введите, какой элемент найти: ";
			cin >> a;
			a = findElemMas(a, mas, n);
			if (a)
				cout << "Данный элемент со значением " << a << endl;
			else
				cout << "Данный элемент не был найден в очереди!\n";
			break;
		case 4:
			if (isEmptyMas(mas))
			{
				cout << "Очередь пустая!\n";
			}
			else
			{
				cout << "Очередь непустая!\n";
			}
			break;
		case 5:
			if (isFullMas(mas, n))
			{
				cout << "Очередь полная!\n";
			}
			else
			{
				cout << "Очередь неполная!\n";
			}
			break;
		case 6:
			masPrint(mas, n);
			break;
		case 7:
			sortMas(mas, n);
			break;
		case 0:
			cout << "Вы точно хотите выйти из программы? (Y/N)\n";
			cin >> c;
			if (c == 'Y')
			{
				delete mas;
				return;
			}
			break;
		default:
			cout << "Вы ввели неверное число!\n";
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 10;
	if (start())
	{
		struct list* root = initList(n);
		printMenu();
		checkAnswerList(root);
	}
	else
	{
		int* mas = initMas(n);
		printMenu();
		checkAnswerMas(mas, n);
	}
	return 0;
}