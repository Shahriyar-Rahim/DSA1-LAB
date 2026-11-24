#include <iostream>
using namespace std;
class queue
{
    int max = 5;
    int q[5];
    int rear;
    int front;

public:
    queue()
    {
        rear = -1;
        front = -1;
    }
    void enqueue(int val)
    {
        if (rear == max - 1)
        {
            cout << " overflow" << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear = rear + 1;
            q[rear] = val;
            // cout<<val<<" ";
        }
    }
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "empty" << endl;
        }
        else
        {
            front = front + 1;
        }
        cout << endl;
    }
    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << " empty " << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << q[i] << " ";
            }
        }
    }
};
int main()
{
    queue q;
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
}