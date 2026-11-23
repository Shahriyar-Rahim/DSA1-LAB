#include<iostream>
#include<string>
#include<bits/stdc++.h>
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
        if(top >= MAX - 1)
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
        if(isEmpty())
        {
            cout <<"Stack underflow!!!\n";
            return;
        }
        top--;
    }

    int maxEl()
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }

        int maxEl = arr[0];
        for(int i = 0; i <= top; i++)
        {
            if(arr[i] > maxEl)
            {
                maxEl = arr[i];
            }
        }
        return maxEl;
    }
    int minEl()
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }

        int minE = arr[0];
        for(int i = 0; i <= top; i++)
        {
            if(arr[i] < minE)
            {
                minE = arr[i];
            }
        }
        return minE;
    }

    int sum()
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }

        int sum = 0;
        for(int i = 0; i < top; i++)
        {
            sum += arr[i];
        }

        return sum;
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "\nCurrent Stack\n";
        for(int i = top; i >= 0; i--)
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
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin>> val;
        s.push(val);
    }

    s.display();

    cout <<"\nMaximum element of the stack is: " << s.maxEl() << endl;
    cout <<"\nMinimum element of the stack is: " << s.minEl() << endl;
    cout <<"\nSum of the stack elements is: " << s.sum() << endl;

    return 0;
}
