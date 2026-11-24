#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class Stack{
    public:
    int arr[MAX];
    int top = - 1;

    void push(int v) {
        if(top == MAX -1) return;

        arr[++top] = v; 
    }

    void pop() {
        if(top == -1) return;
        top--;
    }

    int getMax() {
        int max = arr[0];
        for(int i = 1; i <= top; i++){
            if(arr[i] > max) max = arr[i];
        }
        return max;
    }

    void revStack() {
        int l = 0, r = top;

        while(l < r) {
            int t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
        }
    }

    void display() {
        for(int i = top; i > 0; i--) {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

string revStr(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        st.push(s[i]);
    }

    string r = "";
    while(!st.empty()){
        r += st.top();
        st.pop();
    }

    return r;
}

int main() {
    Stack s;
    int n, v;
    cin >> n;

    cout << "How many elements: ";
    cin >> n;

    cout << "Enter Elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v;
        s.push(v);
    }

    s.display();

    s.pop();
    s.display();
    s.revStack();
    s.display();

    string t;
    cin >> t;
    cout << revStr(t);
}