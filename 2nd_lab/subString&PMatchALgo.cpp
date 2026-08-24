#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text = "hello world";
    string pattern = "world";

    // Substring using library: str.substr(pos, count)
    string sub = text.substr(6, 5);
    cout << "Library Substring: " << sub << endl;

    // Pattern Matching using library: str.find(pattern)
    size_t pos = text.find(pattern);

    if (pos != string::npos)
        cout << "Pattern found via find() at index: " << pos << endl;
    else
        cout << "Pattern not found" << endl;

    return 0;
}