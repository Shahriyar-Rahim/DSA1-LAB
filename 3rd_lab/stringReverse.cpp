#include <iostream>
using namespace std;

int main()
{
    string s, rs;
    cout << "Enter a word: ";
    cin >> s;

    for(int i = s.length() - 1; i >= 0; i--){
        rs += s[i];
    }

    cout << "The reversed string is: " << rs << endl;

    return 0;
}