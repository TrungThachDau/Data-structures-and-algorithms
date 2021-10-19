#include <iostream>
using namespace std;
struct PhanSo
{
	int tu;
	int mau;
};
struct Node
{
	PhanSo data;
	Node* next;
};
struct Slist
{
	Node* head;
	Node* tail;
};
Node* createNode(PhanSo x)
{
	Node* p = new Node;
	p->data.tu = x.tu;
	p->data.mau = x.mau;
	p->next = NULL;
	return p;
}
void addTail(Slist& l,Node*p)
{
	if (p==NULL)
		return;
	else
	{
		if (l.head==NULL) l.head = l.tail = p;
		else
		{
			l.tail->next = p;
			l.tail = p;
		}
	}
}
void createList(Slist& l)
{
	PhanSo x;
	for (int i = 1; i <= 6; i++)
	{
		x.tu = rand() % 50;
		x.mau = rand() % 50+1;
		Node* p = createNode(x);
		addTail(l, p);
	}
}
void printList(Slist l)
{
	Node* p = l.head;
	while (p != NULL)
	{
		cout << p->data.tu << "/"<<p->data.mau<<" ";
		p = p->next;
	}
}
int timUCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void rutGonPS(Slist l)
{
	Node* i = l.head;
	while (i != NULL)
	{
		{
			int uc = timUCLN(i->data.tu, i->data.mau);
			i->data.tu = i->data.tu / uc;
			i->data.mau = i->data.mau / uc;
		}
		i = i->next;
	}
	printList(l);
}
int main()
{
	Slist l;
	PhanSo x;
	l.head = l.tail = NULL;
	createList(l);
	printList(l);
	cout << endl;
	cout << "Sau khi rut gon: ";
	rutGonPS(l);
}
