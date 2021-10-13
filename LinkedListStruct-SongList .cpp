#include <iostream>
#include <fstream>
#include <istream>
#include <string>
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
void addTail(Slist&l, Node*p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p; //node phia sau tail =p
		l.tail = p;//tail = p;
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
int timeListen(Slist l)
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
void addMusic(Slist &l)
{
	Node* k = new Node;
	cout << "\nTen bai hat: ";
	cin.getline(k->data.name, 51);
	cout << "\n Tac gia: ";
	cin >> k->data.writer;
	cout << "\nCa si: ";
	cin >> k->data.singer;
	cout << "\nThoi gian: ";
	cin >> k->data.time;
	k->next = NULL;
	addHead(l, k);
}
void deleteHead(Slist& l)
{

	Node* p = l.head;
	l.head = p->next;
	p->next = nullptr;
	delete p;
}
void deleteTail(Slist& l)
{
	if (l.head == nullptr)
		return;
	else
	{
		Node* p = l.tail;
		Node* q = l.head;
		while (q->next != l.tail)
			q = q->next;
		l.tail = q;
		l.tail->next = nullptr;
		delete p;
	}
}
void deleteMusic(Slist& l, int x)
{
	if (x==0)
	{
		deleteHead(l);
	}
	else if (x==sizeof(Slist))
	{
		deleteTail(l);
	}
	else
	{
		Node* p = l.head;
		for (int i = 0; i < x - 1; i++)
		{
			p = p->next;
		}
		Node* q = p->next;
		p->next = p->next->next;
		delete q;
	}
}
void searchX(Slist l,char x[])
{
	
	for (Node* p = l.head; p != NULL; p = p->next)
	{
		if (strcmp(p->data.name, x) == 0)
			cout << x;
		else
			cout << "K tim thay";
	}
	
}
//void sortAlphabet(Slist l)
//{
//	Node* p = l.head;
//	for (int i = 0; i < sizeof(Slist); i++)
//	{
//		for (int j = sizeof(Slist); j > i; j--)
//		{
//			if (strcmp(p->next->data.name,(p->next->data.name)-1) < 0)
//			{
//				struct Slist l = p->next -> data;
//			}
//		}
//	}
//}
void sapXepTheoTen(struct Song* ds, int slsv) {
	int i, j;
	for (i = 0; i < slsv - 1; i++) {
		for (j = slsv - 1; j > i; j--) {
			if (strcmp(ds[j].name, ds[j - 1].name) < 0) {
				struct Song sv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = sv;
			}
		}
	}
}
//int timkiem(Slist l, int p, char GtriTim[])
//{
//	int i = 0;
//	while (i < p)
//	{
//		if (strcmp(p->nexr, GtriTim) == 0)
//			return i;
//		else
//			i++;
//	}
//	return-1;
//}
void printList(Slist l)
{
	int n = 0;
	Node* k = l.head;
	while (k != NULL)
	{
		cout << "Bai hat so " << n << endl;
		cout << "Ten bai hat: " << k->data.name  << endl;
		//cout << "Tac gia:  " << k->data.writer <<endl;
		//cout << "Ca si:  " << k->data.singer <<endl;
		//cout << "Thoi gian:  " << k->data.time <<endl;
		n++;
		k = k->next;
	}
}
int main()
{
	int x;
	char ten[100];
	Slist songList;
	init(songList);
	readList(songList);
	printList(songList);
	cout<<endl<<"Thoi gian nghe nhac: "<<timeListen(songList);
	//addMusic(songList);
	/*cout << endl;
	printList(songList);
	cout << "\nNhap thu tu bai hat muon xoa: ";
	cin >> x;
	deleteMusic(songList, x);
	printList(songList);*/
	cout << "Nhap ten bai hat: ";
	cin >> ten;
	searchX(songList, ten);
	return 0;
}

