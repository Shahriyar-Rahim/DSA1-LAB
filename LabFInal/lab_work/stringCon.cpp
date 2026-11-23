#include<iostream>
#include<string>
using namespace std;

void strCon(string &d, const string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        d.push_back(s[i]);
    }
}

int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    strCon(s1, s2);

    cout << s1 << endl;

    return 0;
}
