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

      void deleteAtFirst();
      void deleteAtEnd();
      void insertAtEnd(int val);
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
        tail=nullptr;
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
        cin >> val;
        insertAtEnd(val);
    }
}

void SingleLinkedList::traverse()
{
    if(head == nullptr)
    {
        cout << "List is empty";
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

    cout << "Deleting the head node\n";
    l.deleteAtFirst();
    //l.deleteAtFirst();
    cout << "New List becomes\n";
    l.traverse();
    cout <<"\ndeleting the last node...\nNew Node becomes:";
    l.deleteAtEnd();
    l.traverse();

    return 0;
}
