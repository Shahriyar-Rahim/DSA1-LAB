#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};
node *head = nullptr;
node *tail = nullptr;
void insertFront(int val)
{
    node *newnode = new node(val);
    if (head == nullptr)
    {
        head = tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void print()
{
    node *temp = head;
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    head = new node(1);
    node *s = new node(2);
    node *t = new node(3);
    head->next = s;
    s->next = t;
    print();
    print();
    insertFront(3);
    print();
}