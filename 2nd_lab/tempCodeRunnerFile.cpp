#include <bits/stdc++.h>
using namespace std;

void minEl(int arr[], int n)
{
    cout << "\nTHe elements of the given array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Min element of the array is: ";
    int m = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (m > arr[i])
            m = arr[i];
    }
    cout << m << endl;
}

int main()
{
    int n;
    cout << "ENter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    minEl(arr, n);

    return 0;
}