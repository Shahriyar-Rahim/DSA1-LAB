#include <iostream>
#include <string>
using namespace std;

int main()
{
    string STR1, STR2;

    cout << "Input main text: ";
    getline(cin, STR1);

    cout << "Input search pattern: ";
    getline(cin, STR2);

    int n = STR1.length();
    int m = STR2.length();
    int i = 0, count = 0;

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
            cout << "Pattern found at index: " << i << endl;
        }
        i++;
    }

    if (count > 0)
    {
        cout << "Total occurrences: " << count << endl;
    }
    else
    {
        cout << "Pattern not detected in the given text." << endl;
    }

    return 0;
}