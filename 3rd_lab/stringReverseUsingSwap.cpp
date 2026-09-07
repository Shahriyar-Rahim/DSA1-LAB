#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main()
{
    string s;
    cout << "Enter a word: ";
    cin >> s;

    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    cout << "The reversed string is: " << s << endl;

    return 0;
}