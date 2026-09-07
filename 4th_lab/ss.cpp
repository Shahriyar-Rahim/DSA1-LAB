#include <iostream>
#include <string>
using namespace std;

int main()
{
    string STR1, SubSTR = "";
    int m, n;

    cout << "Input main text: ";
    getline(cin, STR1);

    cout << "Enter start index: ";
    cin >> m;

    cout << "Enter length: ";
    cin >> n;

    if (m < 0 || m >= STR1.length())
    {
        cout << "Error: Start position out of bounds." << endl;
    }
    else
    {
        int i = m;
        while (i < STR1.length() && n > 0)
        {
            SubSTR += STR1[i];
            i++;
            n--;
        }
        cout << "Resulting Substring: " << SubSTR << endl;
    }

    return 0;
}