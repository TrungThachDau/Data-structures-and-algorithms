#include <iostream>
#include <fstream>
using namespace std;
struct Song
{
	char name[51];
	char writer[41];
	char singer[41];
	int time;
};
struct Node
{
	Song data;
	Node* next;
};
struct Slist
{
	Node* head;
	Node* tail;
};
Slist songList;
void init(Slist& l)
{
	l.head = l.tail = NULL;
}
void addHead(Slist& l, Node* p)
{
	if (p == NULL)
		return;
	else
		if (l.head == NULL)
			l.head = l.tail = p;
		else
		{
			p->next = l.head;
			l.head = p;
		}

}
void readList(Slist& songList)
{
	init(songList);
	int n = 0;
	ifstream f;
	f.open("input.txt");
	if (f.eof())cout << "\n Not Found";
	else
	{
		f >> n;
		for (int i = 1; i <= n; i++)
		{
			Node* p = new Node;
			f >> p->data.name;
			f >> p->data.writer;
			f >> p->data.singer;
			f >> p->data.time;
			p->next = NULL;
			addHead(songList, p);
		}
	}
	f.close();
}
int TimeListen(Slist l)
{
	int s = 0;
	Node* k = l.head;
	while (k != NULL)
	{
		s = s + k->data.time;
		k = k->next;
	}
	return s;
}
void printList(Slist l)
{
	Node* k = l.head;
	while (k != NULL)
	{
		cout << k->data.name << " ";
		k = k->next;
	}
}
int main()
{
	Slist songList;
	init(songList);
	readList(songList);
	printList(songList);
	cout<<endl<<TimeListen(songList);
	return 0;
}
