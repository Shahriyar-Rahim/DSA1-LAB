#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int v);
};

Node::Node(int d)
{
    this->data = d;
    this->next = nullptr;
}

class SingleLinkList
{
    Node* head;
    Node* tail;

public:
    SingleLinkList();
    ~SingleLinkList();

    Node* getHead();
    int getLength();
    void insertAtEnd(int v);
    void takeInp();
    void traverse();
};

SingleLinkList::SingleLinkList()
{
    head = nullptr;
    tail = nullptr;
}

SingleLinkList::~SingleLinkList()
{
    Node* cur = head;
    for(; cur != nullptr;)
    {
        Node* nextNode = cur->next;
        delete cur;
        cur = cur->next;
    }
}

Node* SingleLinkList::getHead() { return head;}

int SingleLinkList::getLength()
{
    int c = 0;
    Node* cur = head;

    for(; cur != nullptr; cur = cur->next)
    {
        c++;
    }
    return c;
}

void SingleLinkList::insertAtEnd(int x)
{
    Node* newNode = new Node(x);

    if(head == nullptr)
    {
        head = tail = newNode;
        cout << "Inserted " << x << " at the only node at the address " << newNode << "\n";
        return;
    }

    tail->next = newNode;
    cout << "\nInserted " << x << " at the node position " << getLength();
}

void SingleLinkList:: takeInp()
{
    int n, val;
    cout << "\nHow many initial node you want?\n";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter value for the node " << i + 1 << ": ";
        cin >> val;
        insertAtEnd(val);
    }
}

void SingleLinkList::traverse()
{
    if(head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    Node* cur = head;
    int index = 1;

    cout << "\nCurrent list:\n";
    for(; cur != nullptr; index++)
    {
        cout << cur->data << " -> ";
        cur = cur->next;
    }
    cout << "nullptr\n";
}

int main()
{
    SingleLinkList l;

    l.takeInp();
    l.traverse();

    return 0;
}
