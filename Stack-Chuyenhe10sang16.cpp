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

	if (s.top == NULL)
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
	return s.top->data;
}
void he10sanghe16(Stack s,int n)
{
	SNode* p;
	while (n > 0)
	{
		p = CreateNode(n % 16);
		push(s, p);
		n /= 16;
	}
	while (!isEmpty(s))
	{
		if (top(s) <= 9)
		{
			cout << top(s);
			pop(s);
		}
		else if (top(s) == 10)
		{
			cout << "A";
			pop(s);
		}
		else if (top(s) == 11)
		{
			cout << "B";
			pop(s);
		}
		else if (top(s) == 12)
		{
			cout << "C";
			pop(s);
		}
		else if (top(s) == 13)
		{
			cout << "D";
			pop(s);
		}
		else if (top(s) == 14)
		{
			cout << "E";
			pop(s);
		}
		else if (top(s) == 15)
		{
			cout << "F";
			pop(s);
		}
	}
}
void he10sanghe16s(Stack s, int n)
{
	SNode* p;
	while (n > 0)
	{
		p = CreateNode(n % 16);
		push(s, p);
		n /= 16;
	}
	while (!isEmpty(s))
	{
		cout << top(s)<<" ";
		pop(s);
	}
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
	int n;
	cout << "Type n: ";
	cin >> n;
	he10sanghe16(s, n);
	cout << endl;

}
