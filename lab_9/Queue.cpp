#include <iostream>
using namespace std;

#define MAX_S 100

class Queue
{
public:
    int front;
    int rear;
    int arr[MAX_S];

    Queue();
    bool isEmpty();
    bool isFull();
    int getFront();
    void enqueue(int val);
    int dequeue();
    void display();
};

Queue::Queue() : front(-1), rear(-1) {}

bool Queue::isEmpty() { return front == -1 || front > rear; }
bool Queue::isFull() { return rear == MAX_S - 1; }

int Queue::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr[front];
}

void Queue::enqueue(int v)
{
    if (isFull())
    {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    arr[++rear] = v;
    cout << v << " queued to the line.\n";
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return -1;
    }

    int val = arr[front++];
    return val;
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(2333);
    q.enqueue(25);

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    return 0;
}