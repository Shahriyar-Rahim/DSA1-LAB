#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define MAX 100

class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int val)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = val;
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!!!\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top];
    }

    // Reverses the order of elements in the Stack
    void reverseStack()
    {
        Stack tempStack;
        while (!isEmpty())
        {
            tempStack.push(peek());
            pop();
        }
        for (int i = 0; i <= tempStack.top; i++)
        {
            this->arr[i] = tempStack.arr[i];
        }
        this->top = tempStack.top;
    }

    // Reverses a string using a character stack (from stack_rev.cpp)
    string reverseString(const string &inp)
    {
        stack<char> st;
        for (char c : inp)
        {
            st.push(c);
        }

        string reversed = "";
        while (!st.empty())
        {
            reversed += st.top();
            st.pop();
        }
        return reversed;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Current Stack:\n";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << "\n";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        s.push(val);
    }

    s.display();

    cout << "Popping top element...\n";
    s.pop();
    s.display();

    cout << "Reversing the stack...\n";
    s.reverseStack();
    s.display();

    cin.ignore();
    string inp;
    cout << "Enter a string to reverse: ";
    getline(cin, inp);
    cout << "Reversed String is: " << s.reverseString(inp) << endl;

    return 0;
}