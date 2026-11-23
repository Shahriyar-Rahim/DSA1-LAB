#include<bits/stdc++.h>
using namespace std;

class Node
{
public:

    int data;
    Node* next;

    Node(int val);
};

Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

class SingleLinkedList
{
    Node* head;
    Node* tail;

public:
    SingleLinkedList();
    ~SingleLinkedList();

    void insertAtFront(int val);
    void insertAtEnd(int val);
    void takeInp();
    void travarse();
};

SingleLinkedList::SingleLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

SingleLinkedList::~SingleLinkedList()
{
    Node* cur = head;
    while(cur!=nullptr)
    {
        Node* nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
}

void SingleLinkedList::insertAtFront(int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;

    if(tail == nullptr) tail = newNode;
}

void SingleLinkedList::insertAtEnd(int val)
{
    Node* newNode = new Node(val);

    if(head == nullptr)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail =  newNode;
}

void SingleLinkedList::takeInp()
{
    int n, val;
    cout << "How many node you want: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter value for node " << i + 1 << ": " ;
        cin >> val;
        //insertAtFront(val); to insert every value at the front
        insertAtEnd(val);

    }
}

void SingleLinkedList::travarse()
{
    if(head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    Node* cur = head;
    cout <<"\nCurrent List\n";
    while(cur!=nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    SingleLinkedList l;

    l.takeInp();
    l.travarse();

    cout << "Give a value to insert at front: ";
    int t;
    cin >> t;
    l.insertAtFront(t);
    cout << "Give a value to insert at end: ";
    cin >> t;
    l.insertAtEnd(t);
    l.travarse();
}







