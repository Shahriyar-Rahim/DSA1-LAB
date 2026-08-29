#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
        }

        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    return 0;
}