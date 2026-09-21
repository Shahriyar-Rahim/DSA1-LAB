#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int v);
};

Node:: Node(int x){
    data = x;
    next = nullptr;
}

class SingleLinkList{
    Node* head;
    Node* tail;

public:
    SingleLinkList();
    ~SingleLinkList();

    Node* getHead();
    int getLength();
    void insertElend(int val);
    void takeInp();
    void travarse();
    void search(int t); // where t is the target value
};

SingleLinkList:: SingleLinkList() {
    head = nullptr;
    tail = nullptr;
}

SingleLinkList :: ~SingleLinkList() {
    Node* cur = head;
    for(; cur != nullptr;){
        Node* nextNode = cur->next;
        delete cur;
        cur = cur->next;
    }
}

Node* SingleLinkList:: getHead() {return head;}

int SingleLinkList:: getLength() {
    int c  = 0;
    Node* cur = head;

    for(; cur != nullptr; cur = cur->next){
        c++;
    }
    return c;
}

void SingleLinkList:: insertElend(int x) {
    Node* newNode = new Node(x);

    if(head == nullptr)
    {
        head = tail = newNode;
        cout << "Inserted " << x << " as the first and only node at address: " << newNode << "\n";
        return;
    }

    tail->next = newNode;
    tail = newNode;
    cout << "Inserted: " << x << " at node position " << getLength()
         << " (New tail) at address: " << newNode << "\n";
}

int main() {
    
    
    return 0;
}