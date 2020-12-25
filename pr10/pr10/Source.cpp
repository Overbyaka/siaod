#include <iostream>

using namespace std;

struct Tree //AVL ������
{
	unsigned char height;
	int value; //�������� ����
	Tree* left; //��������� �� ����� ����
	Tree* right; //��������� �� ������ ����
	Tree(int k) //�����������
	{
		value = k;
		left = NULL;
		right = NULL;
		height = 1;
	}
};
//��������������� ������� ��� ����������� ������
unsigned char height(Tree* p)
{
	return p ? p->height : 0; //���������� ������ ����, ���� ��� �������, ����� 0
}

int balanceFactor(Tree* p)
{
	return height(p->right) - height(p->left); //���������� ������ ������ (������ ������� ��������� ������ ���������� �� ������ ������ �� ����� ��� �� 1)
}

void fixHeight(Tree* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

//������� ��� �������� ������

Tree* rotateRight(Tree* p) // ������� ������ �������
{
	Tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

Tree* rotateLeft(Tree* q) // ������� ����� �������
{
	Tree* p = q->right;
	q->right = p->left;
	p->left = q;
	fixHeight(q);
	fixHeight(p);
	return p;
}

Tree* balanceTree(Tree* p) // ������������ ���� p
{
	fixHeight(p);
	if (balanceFactor(p) == 2) //
	{
		if (balanceFactor(p->right) < 0)
			p->right = rotateRight(p->right); //������� ����� �������
		return rotateLeft(p);
	}
	if (balanceFactor(p) == -2)
	{
		if (balanceFactor(p->left) > 0)
			p->left = rotateLeft(p->left); //������� ������ �������
		return rotateRight(p);
	}
	return p; // ������������ �� �����
}

Tree* insert(Tree* p, int k) // ������� �������� k � ������ � ������ p
{
	if (!p) return new Tree(k);
	if (k < p->value)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balanceTree(p);
}

//�������� ����

Tree* findMin(Tree* p) // ����� ���� � ����������� ������ � ������ p 
{
	return p->left ? findMin(p->left) : p;
}

Tree* removeMin(Tree* p) // �������� ���� � ����������� ������ �� ������ p
{
	if (p->left == 0)
		return p->right;
	p->left = removeMin(p->left);
	return balanceTree(p);
}

Tree* remove(Tree* p, int k) // �������� �������� k �� ������ p
{
	if (!p) return 0;
	if (k < p->value)
		p->left = remove(p->left, k);
	else if (k > p->value)
		p->right = remove(p->right, k);
	else //  k == p->key 
	{
		Tree* q = p->left;
		Tree* r = p->right;
		delete p;
		if (!r) return q;
		Tree* min = findMin(r);
		min->right = removeMin(r);
		min->left = q;
		return balanceTree(min);
	}
	return balanceTree(p);
}

//��� ������ ������ ������������� https://dreampuf.github.io/

void printTree(Tree* p) //p - ������ ������
{
	if (p->left != NULL)
	{
		cout << "\"" << p->value << "\"" << " -> " << "\"" << (p->left)->value << "\"" << "\n";
		printTree(p->left);
	}
	if (p->right != NULL)
	{
		cout << "\"" << p->value << "\"" << " -> " << "\"" << (p->right)->value << "\"" << "\n";
		printTree(p->right);
	}
	
}

int main()
{
	const int n = 10;
	int array[n];
	Tree* root = NULL;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
		root = insert(root, array[i]);
	}
	printTree(root);


	return 0;
}