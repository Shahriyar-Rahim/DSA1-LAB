#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int vowels = 0;
    int consonants = 0;

    for (char c : s)
    {
        if (isalpha(c))
        {
            char lower_c = tolower(c);

            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u')
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