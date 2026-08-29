#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter a word: ";
    cin >> s;

    bool isPalindrome = true;
    int len = s.length();

    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
    {
        cout << s << " is a palindrome" << endl;
    }
    else
    {
        cout << s << " is not a palindrome" << endl;
    }

    return 0;
}