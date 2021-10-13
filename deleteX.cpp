#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
struct slist
{
    node* head;
    node* tail;
};
void init(slist &l)
{
    l.head = l.tail = nullptr;
}
node* createNode(int x)
{
    node* temp = new node;
    temp->next = nullptr;
    temp->data = x;
    return temp;
}
void printList(slist l)
{
    node* k = l.head;
    while (k != nullptr)
    {
        cout << k->data << " ";
        k = k->next;
    }
}
void addTail(slist &l,int x)
{
    node* p = createNode(x);
    if(l.head == nullptr)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p; //node phia sau tail =p
        l.tail = p;//tail = p;
    }
}
void DeleteHead(slist&l )
{
//    if (l.head == nullptr)
//        return;
//    else
//    {
        node* p = l.head;
        l.head = p->next;
        p->next = nullptr;
        delete p;
 //   }
}void DeleteTail(slist& l)
{
    if (l.head == nullptr)
        return;
    else
    {
        node* p = l.tail;
        node* q = l.head;
        while (q->next != l.tail)
            q = q->next;
        l.tail = q;
        l.tail->next = nullptr;
        delete p;
    }
}
void deleteAt(slist& l,int k)
{
    node* p = l.head;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    node* q = p->next;
    p->next = p->next ->next;
    delete q;
}
void createList(slist&l,int n)
{
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        addTail(l,x);
    }
}
int main()
{
    int x,k,n;
    slist l;
    init(l);
    cin>>n;
    createList(l,n);
    printList(l);
    cin >> k;
    if (k == 0)
    {
        DeleteHead(l);
    }
    else if (k == n)
    {
        DeleteTail(l);

    }
    else
    {
        deleteAt(l,k);

    }
    printList(l);
    return 0;
}