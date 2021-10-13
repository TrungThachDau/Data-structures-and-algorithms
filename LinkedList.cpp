#include<iostream>
using namespace std;



// ========== KHAI BĂO Cáº¤U TRĂC 1 CĂI NODE ==========
struct node
{
	int data; // dá»¯ liá»‡u cá»§a node
	struct node *pNext; // con trá» dĂ¹ng Ä‘á»ƒ liĂªn káº¿t giá»¯a cĂ¡c cĂ¡i node vá»›i nhau
};
typedef struct node NODE;

// ========== KHAI BĂO Cáº¤U TRĂC DANH SĂCH LIĂN Káº¾T ÄÆ N =========

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;


// hĂ m khá»Ÿi táº¡o danh sĂ¡ch liĂªn káº¿t Ä‘Æ¡n
void KhoiTaoDanhSach(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
// hĂ m khá»Ÿi táº¡o 1 cĂ¡i node Ä‘á»ƒ chuáº©n bá»‹ thĂªm vĂ o danh sĂ¡ch
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return NULL;
	}
	p->data = x; // Ä‘Æ°a dá»¯ liá»‡u cá»§a biáº¿n x vĂ o data cá»§a cĂ¡i Node p
	p->pNext = NULL; // khá»Ÿi táº¡o node p nhÆ°ng node p chÆ°a cĂ³ liĂªn káº¿t Ä‘áº¿n node nĂ o háº¿t

	return p;
}

// hĂ m thĂªm 1 cĂ¡i node vĂ o Ä‘áº§u danh sĂ¡ch
void ThemDau(LIST &l, NODE *p)
{
	// náº¿u danh sĂ¡ch rá»—ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thĂªm vĂ o cÅ©ng chĂ­nh lĂ  node Ä‘áº§u vĂ  node cuá»‘i
	}
	else
	{
		p->pNext = l.pHead; // cho con trá» p trá» Ä‘áº¿n pHead
		l.pHead = p; // cáº­p nháº­t láº¡i pHead lĂ  node p
	}
}

// hĂ m thĂªm 1 cĂ¡i node vĂ o cuá»‘i danh sĂ¡ch
void ThemCuoi(LIST &l, NODE *p)
{
	// náº¿u danh sĂ¡ch rá»—ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node p thĂªm vĂ o cÅ©ng chĂ­nh lĂ  node Ä‘áº§u vĂ  node cuá»‘i
	}
	else
	{
		l.pTail->pNext = p; // cho con trá» cá»§a pTail trá» Ä‘áº¿n node p
		l.pTail = p; // cáº­p nháº­t láº¡i pTail chĂ­nh lĂ  node p
	}
}

// hĂ m thĂªm node p sau node q <=> náº¿u node p báº±ng node q ?????
void ThemNode_p_SauNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// duyá»‡t tá»« Ä‘áº§u danh sĂ¡ch Ä‘á»ƒ tĂ¬m node q cáº§n thĂªm vĂ o sau 
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE *g = KhoiTaoNode(p->data);
			g->pNext = k->pNext; // cho node p cáº§n thĂªm vĂ o sau node q trá» Ä‘áº¿n node náº±m sau node k <=> cáº­p nháº­t má»‘i liĂªn káº¿t
			k->pNext = g; // cho node q - cÅ©ng chĂ­nh lĂ  node k trá» Ä‘áº¿n node p
		}
	}
}

// hĂ m thĂªm node p trÆ°á»›c node q <=> náº¿u node p báº±ng node q ?????
void ThemNode_p_TruocNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	NODE *h = new NODE;
	// duyá»‡t tá»« Ä‘áº§u danh sĂ¡ch Ä‘á»ƒ tĂ¬m node q cáº§n thĂªm vĂ o sau 
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE *g = KhoiTaoNode(p->data);
			g->pNext = k; // cho node p cáº§n thĂªm vĂ o sau node q trá» Ä‘áº¿n node náº±m sau node k <=> cáº­p nháº­t má»‘i liĂªn káº¿t
			h->pNext = g; // cho node q - cÅ©ng chĂ­nh lĂ  node k trá» Ä‘áº¿n node p
		}
		h = k;
	}
}

// hĂ m xĂ³a Ä‘áº§u
void XoaDau(LIST &l)
{
	// náº¿u danh sĂ¡ch rá»—ng
	if (l.pHead == NULL)
	{
		return;
	}
	NODE *p = l.pHead; // node p lĂ  node sáº½ xĂ³a
	l.pHead = l.pHead->pNext;// cáº­p nháº­t láº¡i l.pHead lĂ  pháº§n tá»­ káº¿ tiáº¿p
	delete p;
}

// xĂ³a cuá»‘i
void XoaCuoi(LIST &l)
{

	// náº¿u danh sĂ¡ch rá»—ng
	if (l.pHead == NULL)
	{
		return;
	}
	// trÆ°á»ng há»£p danh sĂ¡ch cĂ³ pháº§n tá»­
	if (l.pHead->pNext == NULL)
	{
		XoaDau(l);
		return;
	}
	// duyá»‡t tá»« Ä‘áº§u danh sĂ¡ch Ä‘áº¿n tháº±ng káº¿ cuá»‘i
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phĂ¡t hiá»‡n tháº±ng káº¿ cuá»‘i
		if (k->pNext == l.pTail)
		{
			delete l.pTail; // xĂ³a Ä‘i pháº§n tá»­ cuá»‘i
			k->pNext = NULL; // cho con trá» cá»§a node káº¿ cuá»‘i trá» Ä‘áº¿n vĂ¹ng nhá»› null
			l.pTail = k; // cáº­p nháº­t láº¡i l.pTail
			return;
		}
	}
}

// hĂ m xĂ³a 1 node náº±m sau node q trong danh sĂ¡ch
void XoaSauNode_q(LIST &l, NODE *q)
{
	// duyá»‡t danh sĂ¡ch tá»« Ä‘áº§u Ä‘áº¿n cuá»‘i Ä‘á»ƒ tĂ¬m node q
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phĂ¡t hiá»‡n node q
		if (k->data == q->data)
		{
			NODE *g = k->pNext; // node g chĂ­nh lĂ  node náº±m sau node k(náº±m sau node q) <=> node mĂ  ta sáº½ xĂ³a
			k->pNext = g->pNext; // cáº­p nháº­t má»‘i liĂªn káº¿t giá»¯a node k(node q) vá»›i node sau node g 
			delete g; // xĂ³a node náº±m sau node q			
		}
	}
}

// hĂ m xuáº¥t danh sĂ¡ch liĂªn káº¿t Ä‘Æ¡n
void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// hĂ m xĂ³a 1 cĂ¡i node cĂ³ khĂ³a k báº¥t kĂ¬
void XoaNodeCoKhoaBatKy(LIST &l, int x)
{
	// náº¿u danh sĂ¡ch rá»—ng thĂ¬ khĂ´ng lĂ m gĂ¬ háº¿t
	if (l.pHead == NULL)
	{
		return;
	}
	// náº¿u node cáº§n xĂ³a náº±m Ä‘áº§u danh sĂ¡ch
	if (l.pHead->data == x)
	{
		XoaDau(l);
		return;
	}
	// náº¿u node cáº§n xĂ³a náº±m á»Ÿ cuá»‘i danh sĂ¡ch
	if (l.pTail->data == x)
	{
		XoaCuoi(l);
		return;
	}

	NODE *g = new NODE; // node g lĂ  node trá» Ä‘áº¿n node náº±m trÆ°á»›c node cáº§n xĂ³a: x
	// duyá»‡t danh sĂ¡ch liĂªn káº¿t Ä‘Æ¡n Ä‘á»ƒ tĂ¬m
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		// phĂ¡t hiá»‡n pháº§n tá»­ cáº§n xĂ³a
		if (k->data == x)
		{
			g->pNext = k->pNext; // cáº­p nháº­t má»‘i liĂªn káº¿t giá»¯a node k vá»›i node sau node h
			delete k; // xĂ³a node náº±m sau node k	
			return;
		}
		g = k; // cho node g trá» Ä‘áº¿n node k
	}

}

// hĂ m menu
void Menu(LIST &l)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Them node vao danh sach";
		cout << "\n2. Xuat danh sach";
		cout << "\n3. Them node p vao sau node q";
		cout << "\n4. Them node p vao truoc node q";
		cout << "\n5. Xoa dau";
		cout << "\n6. Xoa cuoi";
		cout << "\n7. Xoa node sau node q";
		cout << "\n8. Xoa node co khoa k bat ky";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =========== END ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap gia tri can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemCuoi(l, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH LIEN KET DON \n";
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap node q can them: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			ThemNode_p_SauNode_q(l, q);
		}
		else if (luachon == 4)
		{
			int x;
			cout << "\nNhap node q can them: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			ThemNode_p_TruocNode_q(l, q);
		}
		else if (luachon == 5)
		{
			XoaDau(l);
		}
		else if (luachon == 6)
		{
			XoaCuoi(l);
		}
		else if (luachon == 7)
		{
			int x;
			cout << "\nNhap node q: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			XoaSauNode_q(l, q);
		}
		else if (luachon == 8)
		{
			int x;
			cout << "\nNhap node can xoa: ";
			cin >> x;
			XoaNodeCoKhoaBatKy(l, x);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDanhSach(l);
	Menu(l);
	system("pause");
	return 0;
}
