#include <iostream>
#include <string>
using namespace std;

// Extract substring manually from start index for given length
string manualSubstring(const string &str, int start, int length)
{
    string result = "";
    for (int i = start; i < start + length && i < str.length(); i++)
    {
        result += str[i];
    }
    return result;
}

// Naive Pattern Matching (Returns starting index or -1)
int manualPatternMatch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            return i; // Found match at index i
    }
    return -1; // Not found
}

int main()
{
    string text = "hello world";
    string pattern = "world";

    // Substring
    string sub = manualSubstring(text, 6, 5);
    cout << "Manual Substring: " << sub << endl;

    // Pattern Matching
    int pos = manualPatternMatch(text, pattern);
    if (pos != -1)
        cout << "Pattern found manually at index: " << pos << endl;
    else
        cout << "Pattern not found" << endl;

    return 0;
}