#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* createNode(int init)
{
	Node* p = new Node;
	p->data = init;
	p->left = NULL;
	p->right = NULL;
	return p;
}
typedef Node* Tree;
Tree myTree;
void CreateTree(Tree& root)
{
	root = NULL;
}
void addNode(Tree& root, Node*node)
{
	if (root)
	{
		if (root->data == node->data)
			return;
		else if (node->data <node->data)
			addNode(root->left, node);
		else
		{
			addNode(root->right, node);
		}
	}
	else
	{
		root = node;
	}
}
void NLR(Tree root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		NLR(root->left);
		NLR(root -> right);
	}
}
void LNR(Tree root)
{
	if (root)
	{
		LNR(root->left);
		cout << root->data << " ";
		LNR(root -> right);
	}
}
void LRN(Tree root)
{
	if (root)
	{
		LNR(root->left);
		LNR(root->right);
		cout << root->data << " ";
	}
}
void insertNodeLeft(Tree& root, Node* p)
{
	if (root == NULL || p == NULL) return;
	else if (root->left != NULL) return;
	else
	{
		root->left = p;
	}
}
void insertNodeRight(Tree& root, Node* p)
{
	if (root == NULL || p == NULL) return;
	else if (root->right != NULL) return;
	else
	{
		root->right= p;
	}
}
Node* findNode(Tree root, int x)
{
	if (root == NULL) return NULL;
	else
	{
		if (x < root->data)
			findNode(root->left, x);
		else if (x > root->data)
			findNode(root->right, x);
		else
			return root;
	}
}
void Del(Tree& root)
{
	if (root != NULL)
	{
		if (root->left != NULL) Del(root->left);
		if (root->right != NULL) Del(root->right);
		delete(root);
	}
}
void lietKeNutLonHonX(Tree root, int x)
{
	if (root != NULL)
	{
		if (x < root->data)
		{
			cout << root->data << " ";
		}
		lietKeNutLonHonX(root->left, x);
		lietKeNutLonHonX(root->right, x);
	}
}
void TimNodeTheMang(Tree& root, Tree& y)
//Node y là node thê mạng cho Node cần xóa, đảm nhận nhiệm vụ tìm Node trái nhất hoặc phải
{
	if (y->left != NULL)//duyệt sang bên trái nhất
	{
		TimNodeTheMang(root, y->left);//tìm ra node trái nhất
	}
	else
	{
		root->data = y->data;//cập nhật data của node cần xóa chính là data của node thế mạng
		root = y;//cho node root trỏ đến node thế mạng,
		y = y->right;//cập nhật mối liên kết
	}
}
void deleteNode(Tree &root,int x)
{
	if (root == NULL)	//neu như cây đang rỗng
		return;//kt hàm
	else
	{
		if (x < root->data) // nếu x nhỏ hơn node gốc
		{
			deleteNode(root->left, x);	//duyệt sang nhánh trái
		}
		else if (x > root->data)//nếu  x lớn hơn node gốc
		{
			deleteNode(root->right, x);//duyệt sang nhánh phải
		}
		else
		{
			Node* p = root; //node thế mạng
			if (root->left == NULL)
				root = root->right; //duyệt node sang phải để cập nhật mối liên kết giữa node cha của node cần xóa với node con của node cần xóa
			else if (root->right == NULL)
				root = root -> left;
			//duyệt sang trái để cập nhật mối liên kếtgiữa....
			else// node cần xóa có 2 con
			{//tìm node trái nhất của cây con phải(cây con phải của node cần nóa);
				TimNodeTheMang(p, root->right);
			}
			delete p;//xóa node cần xóa;
		}
	}
}
int countNode(Tree root)
{
	if (!root) return 0;
	int nl = countNode(root->left);
	int nr = countNode(root->right);
	return (1 + nl + nr);
}
int countNodeIsLeaf(Tree root)
{
	if (!root) return 0;
	if (root->left == NULL&&root->right==NULL) return 1;
	int nl = countNodeIsLeaf(root->left);
	int nr = countNodeIsLeaf(root->right);
	return (nl + nr);
}
int countNode2Child(Tree root)
{
	if (!root) return 0;
	if (!root->left || !root->right) return 0;
	int nl = countNode2Child(root->left);
	int nr = countNode2Child(root->right);
	return (nl + nr + 1);
}
void menu(Tree &root,int a[])
{
	int cn;
	do
	{
		cout << "Chon chuc nang: ";
		cin >> cn;
		switch (cn)
		{
		case 1:
		{

			int x;
			for (int i = 1;i<=sizeof(a); i++)
			{
				Node* p = createNode(a[i]);
				addNode(root, p);
			}
			break;
		}
		case 2:
		{
			NLR(root);
			break;
		}
		case 3:
		{
			int x;
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			Node* k = findNode(root, x);
			if (k == NULL)
			{
				cout << "x khong ton tai";
			}
			else
			{
				cout << "x co ton tai";
			}
			break;
		}
		case 4:
		{
			int x;
			cout << "Nhap x can xoa: ";
			cin >> x;
			deleteNode(root, x); break;
		}
		case 5:
		{
			cout << "So nut cua cay: " << countNode;
			cout << "\nSo nut la cua cay: " << countNodeIsLeaf;
			cout << "\nSo nut co 2 con: " << countNode2Child;
		}
		case 6:
		{
			int x;
			cout << "Liet ke nut lon hon x: Nhap x: ";
			cin >> x;
			lietKeNutLonHonX(root, x);
		}

		default:
			break;
		}
	} while (cn!=0);
}
int main()
{
	
	Tree root;
	int a[10]= { 5,2,3,4,7,2,1,1,4,8 };
	CreateTree(root);
	menu(root,a);
	return 0;

}
