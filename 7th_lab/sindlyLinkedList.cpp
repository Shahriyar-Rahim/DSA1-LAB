#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val);
};

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

class SingleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SingleLinkedList();
    ~SingleLinkedList();

    int getLength();
    void insertAtFront(int val);
    void insertAtEnd(int val);
    void insertAtMiddle(int val, int pos);
    
    void deleteAtFront();
    void deleteAtEnd();
    
    void takeInp();
    void traverse();
};

SingleLinkedList::SingleLinkedList() {
    head = nullptr;
    tail = nullptr;
}

SingleLinkedList::~SingleLinkedList() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
}

int SingleLinkedList::getLength() {
    int count = 0;
    Node* cur = head;
    while (cur != nullptr) {
        count++;
        cur = cur->next;
    }
    return count;
}

void SingleLinkedList::insertAtFront(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    
    if (tail == nullptr) {
        tail = newNode;
    }
}

void SingleLinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void SingleLinkedList::insertAtMiddle(int val, int pos) {
    int len = getLength();

    if (pos < 1 || pos > len + 1) {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1) {
        insertAtFront(val);
        return;
    }

    if (pos == len + 1) {
        insertAtEnd(val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the first node (head)
void SingleLinkedList::deleteAtFront() {
    if (head == nullptr) {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    // If list becomes empty after deletion, reset tail as well
    if (head == nullptr) {
        tail = nullptr;
    }
}

// Delete the last node (tail)
void SingleLinkedList::deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    // Single node scenario
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    // Traverse to the second-to-last node
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void SingleLinkedList::takeInp() {
    int n, val;
    cout << "How many node you want: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        insertAtEnd(val);
    }
}

void SingleLinkedList::traverse() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    
    Node* cur = head;
    cout << "\nCurrent List:\n";
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    SingleLinkedList l;
    l.takeInp();
    l.traverse();

    cout << "\nDeleting from front...";
    l.deleteAtFront();
    l.traverse();

    cout << "\nDeleting from end...";
    l.deleteAtEnd();
    l.traverse();

    return 0;
}
