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
    void search(); // where t is the target value
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

void SingleLinkList :: takeInp() {
    int n, val;
    cout << "How many initial node you want?\n";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        insertElend(val);
    }
}

void SingleLinkList::travarse()
{
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

void SingleLinkList::search() {
    int t;
    cout << "ENter the value u want to search: ";
    cin >> t;
    if(head == nullptr){
        cout << "List is empty\n";
        return;
    }

    Node* curr = head;
    int pos = 1;
    bool found = false;

    while (curr != nullptr)
    {
        if(curr->data == t){
            cout << "Found " << t << " at posotion " << pos << " and the address is " << curr << endl;
            found = true;
            break;
        }
        curr = curr->next;
        pos++;
    }

    if(!found){
        cout << "The element " << t << " does not exists\n";
    }
    
}

int main() {
    SingleLinkList l;
    l.takeInp();
    l.search();
    
    return 0;
}