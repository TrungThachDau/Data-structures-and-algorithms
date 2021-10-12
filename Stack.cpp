#include <iostream>
using namespace std;
struct SNode 
{
	int data;
	SNode* next;
};
struct Stack
{
	SNode* top;
};
SNode* CreateNode(int x)
{
	SNode* p = new SNode;
	if (p == NULL)
	{
		cout << "Not enough ememory  allocated.";
		return NULL;
	}
		p->data = x;
		p->next = NULL;
		return p;
}
void initStack(Stack& s)
{
	s.top = NULL;
}
bool isEmpty(Stack s)
{

	if (s.top=NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void push(Stack& s, SNode* p)
{
	if (s.top == NULL)
		s.top = p;
	else
	{
		p->next = s.top;
		s.top = p;
	}
}
int pop(Stack& s)
{
	if (isEmpty(s))
		return 0;
	SNode* p = s.top;
	int data = p->data;
	s.top = p->next;
	delete p;
	return data;
}
int top(Stack s)
{
	if (isEmpty(s))
		return 0;
	return s.top->data;
}
void printStack(Stack s)
{
	SNode* p = s.top;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
int main()
{
	Stack s;
	initStack(s);
	SNode* p;
	for(int i=0;i<10;i++)
	{
		p = CreateNode(i + 1);
		push(s, p);
	}
	printStack(s);
}
