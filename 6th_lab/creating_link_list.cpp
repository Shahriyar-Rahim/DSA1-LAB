#include <iostream>
using namespace std;

// class represents an individual element whhich is called node in memory ---> single node
class Node{
public:
    int data; // it is being used always for insering data to the node
    Node* next; // it refers to the address of the class, class is a single node, so basically it is pointing a nodes address

    Node(int val); // by creating a constructor it will automaticaly create a node with the argumet passed to it also a next value pointer which is always going to be null
};

Node:: Node (int d) {
    data = d;
    next = nullptr;
}

int main() {
    
    
    return 0;
}