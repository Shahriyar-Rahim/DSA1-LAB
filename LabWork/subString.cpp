#include<iostream>
#include<iomanip>
using namespace std;

void substrEx(string &s1, string &s2, int n, int m)
{
    if(m < 0 || m>= s1.length())
    {
        cout <<"Invalid operation\n";
        return;
    }

    int i = m;
    while(i < s1.length() && n > 0)
    {
        s2 += s1[i];
        i++;
        n--;
    }


    cout << "Extracted string:  " << s2 << endl;
}


int main()
{
    string s1, s2 = "";
    int n, m;
    cout << "Enter the string: ";
    getline(cin, s1);

    cout << "The string is: ";
    for(int i = 0; i < s1.length(); i++)
    {
        cout << setw(3) << s1[i];
    }
    cout << endl;

    cout << "Index:         ";
    for(int i = 0; i < s1.length(); i++)
    {
        cout << setw(3) << i;
    }
    cout << endl;
    cout << "Total Length: " << s1.length() << "\n\n";

    cout << "Enter the starting index: ";
    cin >> m;
    cout << "Enter the length of the substring: ";
    cin >> n;

    substrEx(s1, s2, n, m);

    return 0;
}

