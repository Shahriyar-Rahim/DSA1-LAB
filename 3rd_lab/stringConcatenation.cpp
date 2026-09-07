#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cout << "Enter the first string (destination): ";
    cin >> s2;
    cout << "Enter the second string (source to append): ";
    cin >> s1;

    int i = 0;
    while (i < s2.length() && s2[i] != '\0')
    {
        i++;
    }

    int j = 0;
    while (j < s1.length() && s1[j] != '\0')
    {
        s2 += s1[j];
        i++;
        j++;
    }

    cout << "Concatenated string: " << s2 << endl;
    return 0;
}