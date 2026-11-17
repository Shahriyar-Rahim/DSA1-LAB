#include<iostream>
using namespace std;


void patMatch(string &s1, string &s2, int n, int m)
{
    int i = 0;
    int count = 0;

    while(i <= n-m)
    {
        int c = 0;
        for(int j = 0; j < m; j++)
        {
            if(s1[i+j] == s2[j])
                c++;
            else
                j++;
        }

        if(c == m)
        {
            cout << "Found at index: " << i << endl;
            count++;
        }

         i++;
    }

    if(count > 0)
        cout << "Pattern Found " << count << " times\n";
    else
        cout << "Pattern Not found\n";
}


int main()
{
    string s1, s2;

    cout << "Enter the string: ";
    getline(cin, s1);

    cout << "Enter the string: ";
    getline(cin, s2);

    int n = s1.length();
    int m = s2.length();

    cout << "Result: ";
    patMatch(s1, s2, n, m);

    return 0;
}
