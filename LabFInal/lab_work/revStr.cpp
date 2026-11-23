#include<iostream>
using namespace std;


void revStr(string &s)
{
    cout << "The string is: " << s << "\n\n";

    for(int i = 0; i < s.length() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1- i] = temp;
    }

    cout << "The reversed string is: " << s << endl;
}

int main()
{
    string s;

    cout << "Enter the string: ";
    getline(cin, s);

    revStr(s);
}
