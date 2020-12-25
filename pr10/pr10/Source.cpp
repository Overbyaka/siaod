#include <iostream>

using namespace std;

struct Tree //AVL Дерево
{
	unsigned char height;
	int value; //Значение узла
	Tree* left; //Указатель на левый узел
	Tree* right; //Указатель на правый узел
	Tree(int k) //Конструктор
	{
		value = k;
		left = NULL;
		right = NULL;
		height = 1;
	}
};
//Вспомогательные функции для регулировки высоты
unsigned char height(Tree* p)
{
	return p ? p->height : 0; //Возвращаем высоту узла, если она имеется, иначе 0
}

int balanceFactor(Tree* p)
{
	return height(p->right) - height(p->left); //Возвращаем баланс дерева (Высота правого поддерева должно отличаться от высоты левого не более чем на 1)
}

void fixHeight(Tree* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

//Функции для поворота дерева

Tree* rotateRight(Tree* p) // простой правый поворот
{
	Tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

Tree* rotateLeft(Tree* q) // простой левый поворот
{
	Tree* p = q->right;
	q->right = p->left;
	p->left = q;
	fixHeight(q);
	fixHeight(p);
	return p;
}

Tree* balanceTree(Tree* p) // балансировка узла p
{
	fixHeight(p);
	if (balanceFactor(p) == 2) //
	{
		if (balanceFactor(p->right) < 0)
			p->right = rotateRight(p->right); //Большой левый поворот
		return rotateLeft(p);
	}
	if (balanceFactor(p) == -2)
	{
		if (balanceFactor(p->left) > 0)
			p->left = rotateLeft(p->left); //Большой правый поворот
		return rotateRight(p);
	}
	return p; // балансировка не нужна
}

Tree* insert(Tree* p, int k) // вставка значения k в дерево с корнем p
{
	if (!p) return new Tree(k);
	if (k < p->value)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balanceTree(p);
}

//Удаление узла

Tree* findMin(Tree* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left ? findMin(p->left) : p;
}

Tree* removeMin(Tree* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == 0)
		return p->right;
	p->left = removeMin(p->left);
	return balanceTree(p);
}

Tree* remove(Tree* p, int k) // удаление значения k из дерева p
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

//Для вывода дерева воспользуемся https://dreampuf.github.io/

void printTree(Tree* p) //p - корень дерева
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