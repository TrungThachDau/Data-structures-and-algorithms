#include <iostream>
#include <stdlib.h>
#include <time.h>
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
int pop(Queue& q)
{
	if (isEmpty(q))
		return 0;
	QNode* p = q.head;
	int data = p->data;
	q.head = p->next;
	delete p;
	if (q.head == NULL)
		q.tail = NULL;
	return data;
}
int getFront(Queue q)
{
	if (isEmpty(q))
		return 0;
	return q.head->data;
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
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
void random(Queue &q,int a[],int b[],int c[])
{
	int i = 0;
	QNode* p;
	while (i < 10)
	{
		p=createNode(a[rand() % (sizeof(a) - 1 + 1) + 1]);
		push(q, p);
		p = createNode(b[rand() % (sizeof(b) - 1 + 1) + 1]);
		push(q, p);
		p = createNode(c[rand() % (sizeof(c) - 1 + 1) + 1]);
		push(q, p);
		i++;
	}
}
int main()
{
	int a[] = {1,2,3,4,5};
	int b[] = { 11,22,33,44,55 };
	int c[] = { 111,222,333,444,555 };
	int d[100];
	Queue q;
	srand(time(0));
	initQueue(q);
	random(q,a, b, c);
	printQueue(q);
}
