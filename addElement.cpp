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
}
void addElements(slist &l,int x)
{
    node* p = createNode(x);
    if(l.head == NULL)
        l.head = l.tail = p;
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}
void createList(slist&l)
{
    int x, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        addElements(l,x);
    }
}
int main()
{
    slist l;
    init(l);
    createList(l);
    printList(l);
}