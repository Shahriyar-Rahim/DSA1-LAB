#include <iostream>
#include <string>
using namespace std;

void subStringExtraction(const string &STR1, string &SubSTR, int n, int m)
{
    if (m < 0 || m >= STR1.length())
        return;

    int i = m;
    while (i < STR1.length() && n > 0)
    {
        SubSTR += STR1[i];
        i++;
        n--;
    }
}

int main()
{
    string STR1, SubSTR = "";
    int m, n;

    cout << "Enter the target string: ";
    getline(cin, STR1);
    
    cout << "Enter the starting index (m): ";
    cin >> m;

    cout << "Enter the length of substring to extract (n): ";
    cin >> n;

    subStringExtraction(STR1, SubSTR, n, m);

    cout << "Extracted Substring: " << SubSTR << endl;

    return 0;
}