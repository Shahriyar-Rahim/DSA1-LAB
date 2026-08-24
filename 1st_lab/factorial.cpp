#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int main()
{
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    if (num < 0)
    {
        cout << "Factorial is for positive numbers." << endl;
    }
    else
    {
        cout << "Factorial of " << num << " = " << factorial(num) << endl;
    }

    return 0;
}