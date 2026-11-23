#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left, *right;

    Node(int v)
    {
        this->data = v;
        left = nullptr;
        right = nullptr;
    }
};

bool ifNodeExistis(Node* root, int key)
{
    if(root == nullptr)
        return false;
    if(root->data == key)
        return true;

    bool res1 = ifNodeExists(root->left, key);
    if(res1) return true;

    bool res2 = ifNodeExistis(root->right, key);
    return res2;
}

int main()
{
    Node* fnode = new Node(16);
    Node* seNode = new Node(15);
    Node* tnode = new Node(18);

    fnode->left = seNode;
    fnode->right = tnode;
    seNode->left = 10;
    seNode->right = 12;
    tnode->left = 11;
    tnode->right = 19;


    return 0;
}
