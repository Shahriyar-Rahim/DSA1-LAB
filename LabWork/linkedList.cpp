#include<iostream>
using namespace std;

class Node
{
public:
    int d;
    Node* nx;

    Node(int d)
    {
        this->d = d;
        this->nx = nullptr;
    }
};

int main()
{
    Node* head = new Node(10);

    head->nx = new Node(20);
    head->nx->nx = new Node(40);
    head->nx->nx->nx = new Node(50);
    head->nx->nx->nx->nx = new Node(60);

    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->d << " ";
        temp = temp->nx;
    }
    cout << endl;

    return 0;
}
