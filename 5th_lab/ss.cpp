#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int k = 0; k < n - 1; ++k)
    {
        int small = arr[k];
        int pos = k;

        for (int j = k + 1; j < n; ++j)
        {
            if (arr[j] < small)
            {
                small = arr[j];
                pos = j;
            }
        }

        // Manual swap
        int temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}