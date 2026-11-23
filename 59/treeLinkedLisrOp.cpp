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

class BinaryTree
{
private:
    Node* root;

    Node* insertRec(Node* cur, int val)
    {
        if(cur == nullptr) return new Node(val);

        if(val < cur->data)
            cur->left = insertRec(cur->left, val);
        else
            cur->right = insertRec(cur->right, val);

        return cur;
    }

    bool searchRec(Node* cur, int k)
    {
        if(cur == nullptr) return false;
        if(cur->data == k) return true;
        if(k < cur->data) { return searchRec(cur->left, k);}

        return searchRec(cur->right, k);
    }

    void inorder(Node* cur)
    {
        if(cur == nullptr) return;

        inorder(cur->left);
        cout << cur->data << " ";
        inorder(cur->right);
    }

    void destroyRec(Node* cur)
    {
        if(cur == nullptr) return;

            destroyRec(cur->left);
            destroyRec(cur->right);
            delete cur;
    }

public:
    BinaryTree();
    ~BinaryTree();

    void insert(int val);
    bool search(int key);
    void takeInp();
    void inorderr();
};

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    destroyRec(root);
}

void BinaryTree::insert(int val)
{
    root = insertRec(root, val);
}

bool BinaryTree::search(int key)
{
    return searchRec(root, key);
}

void BinaryTree::takeInp()
{
    int n, val;
    cout << "How many nodes u want: ";
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin >> val;
        insert(val);
    }
}

void BinaryTree::inorderr()
{
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
}


int main()
{
    BinaryTree t;
    t.takeInp();
    t.inorderr();

    int key;
    cout << "Enter the vlaue u want to search: ";
    cin>>key;

    if(t.search(key))
    {
        cout << key << " found in the tree\n";
    }
    else cout << key << " not found!!!\n";


    return 0;
}
