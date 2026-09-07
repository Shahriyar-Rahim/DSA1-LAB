#include <iostream>
#include <string>
using namespace std;

void patternMatching(const string &STR1, const string &STR2, int n, int m)
{
    int i = 0;
    int count = 0;

    while (i <= n - m)
    {
        int c = 0;

        for (int j = 0; j < m; j++)
        {
            if (STR1[i + j] == STR2[j])
            {
                c++;
            }
        }

        if (c == m)
        {
            count++;
            cout << "Found at index: " << i << endl;
        }

        i++;
    }

    if (count > 0)
    {
        cout << "\nTotal matches found: " << count << " time(s)." << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}

int main()
{
    string STR1;
    string STR2;

    cout << "Enter the target string: ";
    getline(cin, STR1);

    cout << "Enter the pattern to search: ";
    getline(cin, STR2);

    int n = STR1.length();
    int m = STR2.length();

    cout << "Pattern search result: ";
    patternMatching(STR1, STR2, n, m);

    return 0;
}