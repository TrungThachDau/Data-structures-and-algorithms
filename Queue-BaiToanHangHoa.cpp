#include <iostream>
using namespace std;
	int n;
struct HangHoa
{
	string MaHang;
	string TenHang;
	string DonVi;
	int SoLuong;
};
struct Node
{
	HangHoa data;
	Node* next;
};
struct Queue
{
	Node* head;
	Node* tail;
};
void init(Queue& l)
{
	l.head = l.tail = NULL;
}
bool isEmpty(Queue l)
{
	if (l.head == NULL)
		return 1;
	return 0;
}
void push(Queue& l, Node* p)
{
	if (isEmpty(l))
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void input(Queue& l)
{
	cout << "Nhap so luong: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "\nVat pham thu: " << i;
		Node* p = new Node;
		cout << "\n Ma don hang: ";
		cin >> p->data.MaHang;
		cout << "\n Ten don hang: ";
		cin >> p->data.TenHang;
		cout << "\n Don vi:  ";
		cin >> p->data.DonVi;
		cout << "\n So luong: ";
		cin >> p->data.SoLuong;
		p->next = NULL;
		push(l, p);
	}
}
void printList(Queue l)
{
	int i = 1;
	Node* p = l.head;
	while (p != NULL)
	{
		cout << " \n Vat pham thu: " << i;
		cout << "\n Ma don hang: " << p->data.MaHang;
		cout << "\n Ten don hang: " << p->data.TenHang;
		cout << "\n Don vi: " << p->data.DonVi;
		cout << "\n So luong: " << p->data.SoLuong;
		p = p->next;
	}
}
void getFront(Queue q)
{
	if (isEmpty(q))
		cout<<"\nKhong tim thay hang hoa!";
	else
	{
		cout << "\nThong tin hang hoa: ";
		cout << "\nMa hang hoa: " << q.head->data.MaHang;
		cout << "\nTen hang hoa: " << q.head->data.MaHang;
		cout << "\nDon vi: " << q.head->data.DonVi;
		cout << "\nSo luong: "<<q.head->data.SoLuong;
	}
}

void getRear(Queue q)
{
	if (isEmpty(q))
		cout << "\n Khong tim thay hang hoa!";
	else
	{
		cout << "\nThong tin hang hoa: ";
		cout << "\nMa hang hoa: " << q.tail->data.MaHang;
		cout << "\nTen hang hoa: " << q.tail->data.MaHang;
		cout << "\nDon vi: " << q.tail->data.DonVi;
		cout << "\nSo luong: " << q.tail->data.SoLuong;
	}
}
Node* pop(Queue q)
{
	if (isEmpty(q))
		cout << "\nKhong co hang de xuat kho!";
	else
	{
		Node* p = q.head;
		q.head = p->next;
		delete p;
		if (q.head == NULL)
			q.tail = NULL;
			return p;
	}
}
void popAll(Queue &l,int n)
{
	if (isEmpty(l))
	{
		cout << "Khong tim thay hang hoa!";
		return;
	}
	for (int i = 1; i < n; i++)
	{
		pop(l);
	}
	cout << "Da lay xong!";
}
void searchX(Queue l, string x)
{
	Node* p = l.head;
	while (p != NULL)
	{
		if (p->data.TenHang.compare(x) == 0)
		{
			cout << "\nThong tin hang hoa: ";
			cout << "\nMa hang hoa: " << p->data.MaHang;
			cout << "\nTen hang hoa: " << p->data.MaHang;
			cout << "\nDon vi: " << p->data.DonVi;
			cout << "\nSo luong: " << p->data.SoLuong;
		}
		else
			cout << "Khong tim thay!";
		p = p->next;
	}
}
void menu()
{
	cout << "\n\n1. Nhap danh sach: ";
	cout << "\n2. Xem thong tin hang hoa: ";
	cout << "\n3.Xem mat hang sap xuat kho: ";
	cout << "\n4. Xuat kho mat hang va xem goi hang do: ";
	cout << "\n5. Xem mat hang vua nhap kho: ";
	cout << "\n6. Tim va xem thong tin mat hang: ";
	cout << "\n7. Xuat toan bo hang hoa: ";
	cout << "\n Chon chuc nang: ";
}
int main()
{
	Queue l,l2;
	init(l);
	init(l2);
	int cn;
	do
	{
		menu();
		cin >> cn;
		switch (cn)
		{
		case 1:
		{
			input(l);
			break;
		}
		case 2:
		{
			printList(l);
			break;
		}
		case 3:
		{
			getFront(l); break;
		}
		case 4:
		{
			Node* p=pop(l);
			push(l2,p);
			getFront(l2); break;
		}
		case 5:
		{
			getRear(l); break;
		}
		case 6:
		{
			string x;
			cout << "Tim kiem hang hoa: ";
			cin >> x;
			searchX(l, x); break;
		}
		case 7:
		{
			//popAll(l,n); break;
			cout<<pop(l)->data.TenHang; break;
		}
		default:
			break;
		}
	} while (cn != 0);
	return 0;
}
