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
    l.head = l.tail = NULL;
}
node* createNode(int x)
{
    node* temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}
void printList(slist l)
{
    node* k = l.head;
    while (k != NULL)
    {
        cout << k->data << " ";
        k = k->next;
    }
}
void addTail(slist &l,int x)
{
    node* p = createNode(x);
    if(l.head == NULL)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p; //node phia sau tail =p
        l.tail = p;//tail = p;
    }
}
void addHead(slist& l, int x)
{
    node*p=createNode(x);
    if (l.head == NULL)
        l.head = l.tail = p;
    else
    {
        p->next = l.head;//con tro sau p la node dau
        l.head = p;
    }
}
node* searchNode(slist l, int x)
{
    node* k = l.head;
    while (k != NULL)
    {
        if (k->data == x)
            return k;
        k = k->next;
    }
    return NULL;
}
void addAfter(slist& l, int k, int x)
{
    node* p = createNode(x);
    node* q = searchNode(l,k);  
        if (q == l.tail)
            addTail(l, x);
        else
        {
            p->next = q->next;
            q->next = p;
        }
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
    int x, k,n;
    slist l;
    init(l);
    cin >> n;
    createList(l,n);
    printList(l);
    cout << "\nLocation? ";
    cin >> k;
    cout << "\nX? ";
    cin >> x;
    if (k == 0)
    {
        addHead(l,x);
    }
    else if (k == n)
    {
        addTail(l, x);
    }
    else
    {
        addAfter(l, k, x);
    }
    printList(l);
    return 0;
}