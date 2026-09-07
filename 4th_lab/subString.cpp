#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void subStringExtraction(const string &STR1, string &SubSTR, int n, int m)
{
    if (m < 0 || m >= STR1.length()){
        cout << "Invalid starting index\n";
        return;
    }

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

    cout << "\nThe string is: ";
    for (int i = 0; i < STR1.length(); i++)
    {
        cout << setw(3) << STR1[i];
    }
    cout << endl;

    cout << "Index:         ";
    for(int i = 0; i < STR1.length(); i++){
        cout << setw(3) << i;
    }
    cout << "\n";
    cout << "Total length: " << STR1.length() << endl<< endl;
    
    cout << "Enter the starting index (m): ";
    cin >> m;

    cout << "Enter the length of substring to extract (n): ";
    cin >> n;

    subStringExtraction(STR1, SubSTR, n, m);

    cout << "Extracted Substring: " << SubSTR << endl;

    return 0;
}