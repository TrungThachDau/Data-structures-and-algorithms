

#include <iostream>
#include <stack>
using namespace std;
struct Node
{
	int data;
	Node* next;

};
struct Stack
{
	Node* head;
};
void init(Stack& qu)
{
	qu.head = NULL;

}
void Push(Stack& s, Node* node)
{
	if (s.head == NULL)
		s.head = node;
	else
	{
		node->next = s.head;
		s.head = node;
	}
}

Node* createNode(int x)
{
	Node* temp = new Node;
	temp->next = NULL;
	temp->data = x;
	return temp;
}
int isEmpty(Stack qu)
{
	if (qu.head == NULL)
		return 1;
	else
		return 0;
}
int Top(Stack s)
{
	if (isEmpty(s))
		return 0;
	return s.head->data;
}
int Pop(Stack& s)
{
	if (isEmpty(s))
		return 0;
	Node* node = s.head;
	int data = node->data;
	s.head = node->next;
	delete node; 
	return data;
}
void kiemTraTrungLap(Stack &s,string exp)
{
	if (exp.length() <= 3)
		return;

	for (char c : exp)
	{
		if (c != ')') 
		{
			Node* p = createNode(c);
			Push(s, p);
		}
		else
		{
			if (Top(s) == '(')
			{
				cout << "Tim thay dau ngoac trung lap.";
				return;
			}
			while (Top(s) != '(')
				Pop(s);
			Pop(s);
		}
	}
	cout << "Khong tim thay dau ngoac trung lap.";
}

int main()
{
	string exp = "((x+y))";
	Stack s;
	init(s);
	kiemTraTrungLap(s,exp);

	return 0;
}
