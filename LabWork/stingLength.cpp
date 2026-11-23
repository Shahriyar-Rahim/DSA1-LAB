#include<iostream>
using namespace std;

void lenSTtr(string str)
{
    cout << "The string is: " << str << "\n\n";
    int i = 0;
    for(auto s: str)
        i++;

    cout << "The length of the given string is: " << i << endl;
}


int main()
{
    string s;

    cout << "Enter the string: ";
    getline(cin, s);

    lenSTtr(s);

    return 0;
}
