#include<iostream>
#include<stack>
#include<string>
using namespace std;


string rev(string& inp)
{
    stack<char> st;

    for(char c : inp)
    {
        st.push(c);
    }

    string reversed = "";

    while(!st.empty())
    {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main()
{
    string inp;
    getline(cin, inp);

    cout << "Reversed String is: " << rev(inp) << endl;

    return 0;
}
