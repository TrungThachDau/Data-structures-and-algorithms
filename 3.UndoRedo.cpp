#include <iostream>
#include <string>
using namespace std;
void menu()
{
	cout << "\n1. Nhap noi dung: ";
	cout << "\n2. Xem noi dung";
	cout << "\n3. Hoan tac";
	cout << "\n4. Lap lai";
	cout << "\nChon chuc nang: ";
}
struct Node
{
	string data;
	Node* next;
};
struct Stack
{
	Node* top;
};
Node* CreateNode(string x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
void init(Stack& s)
{
	s.top = NULL;
}
bool isEmpty(Stack s)
{
	if (s.top = NULL)
	{
		return true;
	}
	return false;
}
void push(Stack& s, Node* p)
{
	if (s.top == NULL)
	{
		s.top = p;
	}
	else
	{
		p->next = s.top;
		s.top = p;
	}
}
string pop(Stack& s)
{
	if (isEmpty(s))
		return 0;
	Node* p = s.top;
	string data = p->data;
	s.top = p->next;
	delete p;
	return data;
}
string top(Stack s)
{
	return s.top->data;
}
void print(Stack s)
{
	Node* p = s.top;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
void doo(Stack &s1)
{
	string c;
	cout << "\nNhap noi dung: ";
	cin >> c;
	Node* p;
		p = CreateNode(c);
		push(s1, p);
	}
void undo(Stack& s1,Stack&s2)
{
	Node* p;
	p = CreateNode(pop(s1));
	push(s2, p);

}
void redo(Stack& s1, Stack &s2)
{
	Node* p = CreateNode(pop(s2));
	push(s1, p);
}
int main()
{
	Stack s1, s2;
	init(s1);
	init(s2);
	int chucnang;
	do
	{
		menu();
		cin >> chucnang;
		switch (chucnang)
		{
		case 1:
		{
			doo(s1);
			 cout << endl;
			print(s1); break;

		}
		case 2:
		{
			cout << endl;
			print(s1); break;
		}
		case 3:
		{
			undo(s1, s2); cout << endl;
			print(s1); break;
		}
		case 4:
		{
			redo(s1, s2); cout << endl;
			print(s1); break;
		}
		default:
			break;
		}
	} while (chucnang!=0);
	return 0;
}

