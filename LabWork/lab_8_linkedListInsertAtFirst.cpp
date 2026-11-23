#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
    int data;
    Node* next;

    Node (int val);
};

Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

Node* insertAtFront(Node* head, int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

void printList(Node* head)
{
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    int data = 54;
    head = insertAtFront(head, data);
    printList(head);
    return 0;
}

