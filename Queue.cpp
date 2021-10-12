#include <iostream>
using namespace std;
struct QNode
{
	int data;
	QNode* next;
};
struct Queue
{
	QNode* head;
	QNode* tail;
};
QNode* createNode(int x)
{
		QNode* p = new QNode;
		if (p == NULL)
		{
			cout << "Not enough ememory  allocated.";
			return NULL;
		}
		p->data = x;
		p->next = NULL;
		return p;

}
void initQueue(Queue& q)
{
	q.head = q.tail = NULL;
}
bool isEmpty(Queue q)
{
	if (q.head == NULL)
		return 1;
	return 0;
}
void push(Queue& q, QNode* p)
{
	if (isEmpty(q))
	{
		q.head = p;
		q.tail = p;
	}
	else
	{
		q.tail->next = p;
		q.tail = p;
	}
}
QNode* pop(Queue& q)
{
	if (isEmpty(q))
		return 0;
	QNode* p = q.head;
	//int data = p->data;
	q.head = p->next;
	p->next = NULL;;
	if (q.head == NULL)
		q.tail = NULL;
	return p;
}
int getFront1(Queue q)
{
	if (isEmpty(q))
		return 0;
	return q.head->data;
}
void getFront(Queue q)
{
	if (isEmpty(q))
		cout<<"Rong";
	cout << q.head->data;
}
int getRear(Queue q)
{
	if (isEmpty(q))
		return 0;
	return q.tail->data;
}
void showQueue(Queue q)
{
	if (isEmpty(q) == 1)
	{
		cout << "\nEmpty Queue";
		return;
	}
	cout << "Hang cho da lay: ";
	QNode* p = q.head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
void printQueue(Queue q)
{
	QNode* p = q.head;
	while (p!= NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
void menu()
{
	cout << "\n1. Them phan tu vao hang cho";
	cout << "\n2. Xem phan tu dau hang cho";
	cout << "\n3. Xem phan tu cuoi hang cho";
	cout << "\n4. Lay phan tu ra khoi hang cho";
	cout << "\n5. Lay toan bo noi dung";
	cout << "\nChon chuc nang: ";
}
int main()
{
	int chucnang;
	Queue q;
	initQueue(q);
	do
	{
		menu();
		cin >> chucnang;
		switch (chucnang)
		{
		case 1:
		{
			QNode* p;
			int n;
			cout << "Nhap so luong phan tu: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				p = createNode(rand() % 50);
				push(q, p);
			}
			printQueue(q);
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "\nPhan tu dau hang cho: ";
			getFront(q);
			break;
		}
		case 3:
		{
			cout << "\nPhan tu o cuoi hang cho: ";
			cout << getRear(q); break;
		}
		case 4:
		{
			pop(q);
			cout << "\n Da lay xong."<<endl;
			printQueue(q); break;
		}
		case 5:
		{
			showQueue(q);
			cout << "\n Da lay toan bo noi dung."; break;
		}
		default:
			break;
		}
	} while (chucnang!=0);
	return 0;
}
