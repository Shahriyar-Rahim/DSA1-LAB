#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int val) {
            data = val;
            next = nullptr;
        }
};

class SingleLinkedList{
    Node* head;
    Node* tail;

    public:
        SingleLinkedList(){
            head  = nullptr;
            tail = nullptr;
        }

        ~SingleLinkedList(){
            Node* cur = head;
            while(cur != nullptr) {
                Node* nextNode = cur->next;
                delete cur;
                cur = nextNode;
            }
        }

        void insertAtBeginning(int val)
}

int main() {
    
    
    return 0;
}