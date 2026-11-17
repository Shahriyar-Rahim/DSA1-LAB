#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evalPost(const string &exp)
{
    stack<int> st;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ')
        {
            continue;
        }
        if (isdigit(exp[i]))
        {
            int num = 0;
            while (i < exp.length() && isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
        else
        {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            switch (exp[i])
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            case '/':
                if (val2 == 0)
                {
                    cout << "Division by zero!" << endl;
                    return -1;
                }
                st.push(val1 / val2);
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin, exp);

    cout << "Result of postfix evaluation: " << evalPost(exp) << endl;

    return 0;
}