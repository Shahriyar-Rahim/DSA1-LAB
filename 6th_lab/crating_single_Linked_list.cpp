#include <iostream>
using namespace std;

// class represents an individual element whhich is called node in memory ---> single node
class Node
{
public:
    int data;   // it is being used always for insering data to the node
    Node *next; // it refers to the address of the class, class is a single node, so basically it is pointing a nodes address

    Node(int val); // by creating a constructor it will automaticaly create a node with the argumet passed to it also a next value pointer which is always going to be null
};

Node::Node(int d)
{
    data = d;
    next = nullptr;
}

class SingleLinkedList{
    Node* head; // pointing to the memory address of head, means stores the address
    Node* tail; // stores the memory address of tail node

public:
    SingleLinkedList(); // this constructor will initialize an empty list by adding nullptr to each
    ~SingleLinkedList(); // to dealocate memorty, aslo avoiding memory leaks

    Node* getHead(); // returns the head for node checking (traversing or just checking)
    int getLength(); // method to get the total length of the list ---> basically lenght of the total nodes

    void insertAtEnd(int val); // it will add the nodes one after one, acting as a helper for taking input also isserting at the last el
    void takeInput(); //  to crate the linked list using n inputs (size of the list --> maximum amount of node)
    void traverse(); // to print all the elements of the node
};

SingleLinkedList:: SingleLinkedList() {
    head = nullptr;
    tail = nullptr;
}

SingleLinkedList :: ~SingleLinkedList() {
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    
}

Node* SingleLinkedList :: getHead() {
    return head;
}

int SingleLinkedList :: getLength() {
    int c = 0;
    Node* curr = head;

    for(;curr != nullptr; curr = curr->next){
        c++;
    }
    return c;
}

void SingleLinkedList :: insertAtEnd(int x) {
    Node* newNode = new Node(x);

    if(head == nullptr){
        head = tail = newNode;
        cout << "Inserted " << x << " as the first and only node at address: " << newNode << "\n";
        return;
    }

    tail->next = newNode;
    tail = newNode;
    cout << "Inserted: " << x << " at node position " << getLength()
        << " (New tail) at address: " << newNode << "\n";
}

void SingleLinkedList :: takeInput() {
    int n, val;
    cout << "How many initial node you want?\n";
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        insertAtEnd(val);
    }
}

void SingleLinkedList:: traverse() {
    // if the list is empty
    if(head == nullptr){
        cout << "\nList is Empty: nulllptr\n";
        return;
    }

    Node* cur = head;
    int nodeIndx = 1;
    cout<< "\nCurrent list:\n";
    for(; cur != nullptr; nodeIndx++){
        // cout <<"Node no: " << nodeIndx << " -- Data: " << cur->data
        //     << " -- Addre: " << cur << " Next: " << cur->next << " -> ";
        // cur = cur->next;
        cout << cur->data << " -> ";
        cur = cur -> next;
    }
    cout << "nullptr\n";
}


int main() {
    SingleLinkedList l;
    
    l.takeInput();
    l.traverse();
    
    return 0;
}