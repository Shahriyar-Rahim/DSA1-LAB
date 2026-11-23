#include<iostream>
using namespace std;

void strCon(string &str, string &str2)
{
    cout << "String 1: " << str << endl;
    cout << "String 2: " << str2 << endl;

    for(int i = 0; str[i] != '\0'; i++)
    {
        str2 += str[i];
    }

    cout << "Concatenated string: " << str2 << endl;
}

int main()
{
    string s1, s2;
    cout << "Enter the string: ";
    getline(cin, s1);
    cout << "Enter the string: ";
    getline(cin, s2);

    strCon(s2, s1);

    return 0;
}
