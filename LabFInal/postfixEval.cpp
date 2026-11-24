#include<bits/stdc++.h>
using namespace std;

int evalPost(string exp) {
    stack<int> st;

    for(int i = 0; i<exp.length(); i++) {
        if(exp[i] == ' ') continue;

        if(isdigit(exp[i])){
            int num = 0;
            while(i < exp.length() && isdigit(exp[i])){
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(exp[i] == '+') st.push(a+b);
            else if (exp[i] == '-')
                st.push(a - b);
            else if (exp[i] == '*')
                st.push(a * b);
            else if (exp[i] == '/')
                st.push(a / b);
        }
    }
    return st.top();
}

int main() {
    string p;

    getline(cin, p);
    cout << evalPost(p);
}