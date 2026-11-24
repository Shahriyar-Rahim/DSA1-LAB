#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int v) {
        data = v;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head = nullptr;

    void insertFirst(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertMiddle(int v, int p) {
        if(p <= 1 || head == nullptr) {
            insertFirst(v);
            return;
        }

        Node* temp = head;
        for(int i = 1; i < p - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(v);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertEnd(int v) {
        Node* newNode = new Node(v);
        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteFirst() {
        if(head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if(head == nullptr) {
            return;
        }

        if(head->next  ==  nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void display() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    int n, v;

    cout << "How many nodes u want: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin>>v;
        l.insertEnd(v);
    }

    l.display();

    l.insertFirst(3425);
    l.display();
    l.insertEnd(45);
    l.display();
    l.insertMiddle(4, 5);
    l.display();
    l.deleteEnd();
    l.display();
    l.deleteFirst();
    l.display();

    return 0;
}