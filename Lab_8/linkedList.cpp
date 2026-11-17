#include<iostream>
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

    void insertAtBeginning(int val);
    void insertAtMiddle(int val, int pos);
    void insertAtEnd(int val);
    void deleteAtFirst();
    void deleteAtEnd();
    void takeInp();
    void traverse();
};

SingleLinkedList::SingleLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

SingleLinkedList::~SingleLinkedList()
{
    Node* cur = head;
    while(cur != nullptr)
    {
        Node* nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
}

void SingleLinkedList::insertAtBeginning(int val)
{
    Node* newNode = new Node(val);

    if(head == nullptr)
    {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void SingleLinkedList::insertAtMiddle(int val, int pos)
{
    if(pos <= 1 || head == nullptr)
    {
        insertAtBeginning(val);
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos - 1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    if(temp->next == nullptr)
    {
        insertAtEnd(val);
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
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
    tail = newNode;
}

void SingleLinkedList::deleteAtFirst()
{
    if(head == nullptr)
        return;

    Node* temp = head;
    head = head->next;
    delete temp;

    if(head == nullptr)
        tail = nullptr;
}

void SingleLinkedList::deleteAtEnd()
{
    if(head == nullptr)
        return;

    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->next != tail)
    {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void SingleLinkedList::takeInp()
{
    int n, val;
    cout << "How many node you want: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtEnd(val);
    }
}

void SingleLinkedList::traverse()
{
    if(head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* cur = head;
    cout << "List is: ";
    while(cur != nullptr)
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
    l.traverse();

    cout << "\nInserting 5 at beginning:\n";
    l.insertAtBeginning(5);
    l.traverse();

    cout << "\nInserting 15 at position 3:\n";
    l.insertAtMiddle(15, 3);
    l.traverse();

    cout << "\nInserting 40 at end:\n";
    l.insertAtEnd(40);
    l.traverse();

    cout << "\nDeleting the head node:\n";
    l.deleteAtFirst();
    l.traverse();

    cout << "\nDeleting the last node:\n";
    l.deleteAtEnd();
    l.traverse();

    return 0;
}
