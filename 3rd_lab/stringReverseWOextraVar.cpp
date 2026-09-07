#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter a word: ";
    cin >> s;

    for (int i = 0; i < s.length() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1 - i] = temp;
    }

    cout << "The reversed string is: " << s << endl;

    return 0;
}