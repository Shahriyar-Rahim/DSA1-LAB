#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    Node *root;

    bool searchRec(Node *cur, int key)
    {
        if (cur == nullptr)
            return false;
        if (cur->data == key)
            return true;
        return searchRec(cur->left, key) || searchRec(cur->right, key);
    }

    void inorderRec(Node *cur)
    {
        if (cur == nullptr)
            return;
        inorderRec(cur->left);
        cout << cur->data << " ";
        inorderRec(cur->right);
    }

    void printTreeRec(Node *cur, string indent, bool isRight)
    {
        if (cur == nullptr)
            return;
        cout << indent << (isRight ? "R----" : "L----") << cur->data << endl;
        indent += (isRight ? "     " : "|    ");
        printTreeRec(cur->left, indent, false);
        printTreeRec(cur->right, indent, true);
    }

    void destroyRec(Node *cur)
    {
        if (cur == nullptr)
            return;
        destroyRec(cur->left);
        destroyRec(cur->right);
        delete cur;
    }

public:
    BinaryTree() { root = nullptr; }
    ~BinaryTree() { destroyRec(root); }

    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();

            if (cur->left == nullptr)
            {
                cur->left = newNode;
                return;
            }
            else
                q.push(cur->left);

            if (cur->right == nullptr)
            {
                cur->right = newNode;
                return;
            }
            else
                q.push(cur->right);
        }
    }

    bool search(int key) { return searchRec(root, key); }

    void inorder()
    {
        cout << "Inorder: ";
        inorderRec(root);
        cout << endl;
    }

    void printTree()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty\n";
            return;
        }
        cout << "\nBinary Tree Structure:\n"
             << root->data << endl;
        printTreeRec(root->left, "", false);
        printTreeRec(root->right, "", true);
    }
};

int main()
{
    BinaryTree t;
    int n, val;
    cout << "How many nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        t.insert(val);
    }

    t.printTree();
    t.inorder();

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    if (t.search(key))
        cout << key << " found in the tree." << endl;
    else
        cout << key << " not found in the tree." << endl;

    return 0;
}