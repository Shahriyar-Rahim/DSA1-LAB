#include<iostream>
using namespace std;

int main(){
    string s;
    cout << "Enter a word: ";
    cin >> s;

    int sum = 0;
    for(auto i : s )
        sum ++;

    cout << "The length of the string is: " << sum;
    cout << endl;
}