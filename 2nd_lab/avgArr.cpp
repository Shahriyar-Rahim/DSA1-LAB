#include <bits/stdc++.h>
using namespace std;

void avgArr(int arr[], int n)
{
    cout << "\nTHe elements of the given array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Sum of the array is: ";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;

    cout << "Average of the element is: " << sum / double(n) << endl;;
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

    avgArr(arr, n);

    return 0;
}