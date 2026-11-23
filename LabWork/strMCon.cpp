#include<iostream>
#include<string>
using namespace std;

void strC(string& str, string & strx)
{
    int i = 0, j = 0;

    while(i < strx.length() && strx[i] != '\0')
    {
        i++;
    }

    while(j < str.length() && str[j] != '\0')
    {
        strx += str[j];
        i++;
        j++;
    }
}

int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    strC(s2, s1);

    cout << "Result: " << s1 << endl;

    return 0;
}
