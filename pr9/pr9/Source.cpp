#include <iostream>
#include <locale.h>

using namespace std;

struct list
{
	int value;
	int n; //����������� �������
	struct list* link;
};

struct list* initList(int n) // n- ������������ ����� ����� � �������
{
	struct list* lst;
	lst = (struct list*)malloc(sizeof(struct list)); // ��������� ������ ��� ������ ������
	lst->n = n;
	lst->value = NULL;
	lst->link = NULL; // ��� ��������� ���� ������
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

void addElemList(list* root, int adding) //���������� �������� � �������
{
	struct list* temp1;
	temp1 = (struct list*)malloc(sizeof(list));
	struct list* temp = root;
	if (isFullList(root) == true)
	{
		cout << "������! ������� �����������!\n";
		return;
	}

	while (temp->value != NULL) //���������� �� �����, ���� �� ������ �� ����� �������
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
		cout << "������! ������� �����������!\n";
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

struct list* deletElemList(list* root) //�������� �������� �� �������, ���������� ����� ������ �������
{
	struct list* temp;
	if (isEmptyList(root))
	{
		cout << "������! ������� ������!\n";
		return root;
	}

	temp = root->link;
	free(root); // ������������ ������ �������� �����
	cout << "������� ������\n";
	return temp;
}

void deletElemMas(int* mas, int n)
{
	if (isEmptyMas(mas))
	{
		cout << "������! ������� ������!\n";
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
		printf("%d\n", temp->value); // ����� �������� �������� p
		temp = temp->link; // ������� � ���������� ����
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
		cout << "������! ������� �� �� ����� ���������!\n";
		return;
	}
	int max = 0, maxN = 0;
	int* mas1 = new int[n];
	int count = 0;
	for (int i = 0; i < n; i++)//��� ������������ �����
	{
		if (mas[i] > max)
			max = mas[i];
	}
	while (max > 9)//��� ���������� �������� � ������������ �����
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
	cout << "[1]: �������� ������� � �������\n";
	cout << "[2]: ������� ������� �� �������\n";
	cout << "[3]: �������� �������� �������� �������\n";
	cout << "[4]: ���������, �� ����� �� �������\n";
	cout << "[5]: ���������, �� ����� �� �������\n";
	cout << "[6]: ������� �������\n";
	cout << "[7]: ��������� ���������� (��� ������ ����������)\n";
	cout << "[0]: �����\n";
}

void printFirstMenu()
{
	cout << "�� �������� � ������������ �������� ��� � ���������������� ������������ �������?\n";
	cout << "[0]: ������������ ������\n";
	cout << "[1]: ���������������� ������������ ������\n";
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
		cout << "�������, ��� �� ������ �������: ";
		cin >> answer;
		switch (answer)
		{
		case 1:
			cout << "������� ����� �������� �� ������ ������: ";
			cin >> a;
			addElemList(root, a);
			break;
		case 2:
			root = deletElemList(root);
			break;
		case 3:
			cout << "�������, ����� ������� �����: ";
			cin >> a;
			a = findElemList(a, root);
			if (a)
				cout << "������ ������� �� ��������� " << a << endl;
			else
				cout << "������ ������� �� ��� ������ � �������!\n";
			break;
		case 4:
			if (isEmptyList(root))
			{
				cout << "������� ������!\n";
			}
			else
			{
				cout << "������� ��������!\n";
			}
			break;
		case 5:
			if (isFullList(root))
			{
				cout << "������� ������!\n";
			}
			else
			{
				cout << "������� ��������!\n";
			}
			break;
		case 6:
			listPrint(root);
			break;
		case 0:
			cout << "�� ����� ������ ����� �� ���������? (Y/N)\n";
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
			cout << "�� ����� �������� �����!\n";
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
		cout << "�������, ��� �� ������ �������: ";
		cin >> answer;
		switch (answer)
		{
		case 1:
			cout << "������� ����� �������� �� ������ ������: ";
			cin >> a;
			addElemMas(mas, a, n);
			break;
		case 2:
			deletElemMas(mas, n);
			break;
		case 3:
			cout << "�������, ����� ������� �����: ";
			cin >> a;
			a = findElemMas(a, mas, n);
			if (a)
				cout << "������ ������� �� ��������� " << a << endl;
			else
				cout << "������ ������� �� ��� ������ � �������!\n";
			break;
		case 4:
			if (isEmptyMas(mas))
			{
				cout << "������� ������!\n";
			}
			else
			{
				cout << "������� ��������!\n";
			}
			break;
		case 5:
			if (isFullMas(mas, n))
			{
				cout << "������� ������!\n";
			}
			else
			{
				cout << "������� ��������!\n";
			}
			break;
		case 6:
			masPrint(mas, n);
			break;
		case 7:
			sortMas(mas, n);
			break;
		case 0:
			cout << "�� ����� ������ ����� �� ���������? (Y/N)\n";
			cin >> c;
			if (c == 'Y')
			{
				delete mas;
				return;
			}
			break;
		default:
			cout << "�� ����� �������� �����!\n";
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