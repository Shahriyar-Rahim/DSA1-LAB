#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class Queue{
    public:
    int arr[MAX];
    int front = -1, rear = -1;

    void enqueue(int v) {
        if(rear == MAX -1) {
            return;
        }
        if(front == -1) front = 0;
        arr[++rear] = v;
    }

    void dequeue(){
        if(front == -1 || front > rear) {
            return;
        }
    }

    void display() {
        if(front == -1 || front > rear) {
            return;
        }
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int n, v;
    cout << "How many elements do u want?\n";
    cin>>n;

    cout << "Enter elements: ";
    for(int  i = 0; i < n; i++) {
              cin>>v;
              q.enqueue(v);
    }

    q.display();

    q.dequeue();

    q.display();

    return 0;
}