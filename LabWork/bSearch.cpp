#include<iostream>
using namespace std;

int bSearch(int arr[], int n, int v)
{
    cout << "The element of the array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == v)
        {
            return mid;
        }
        if(arr[mid] < v)
        {
            low = mid + 1;
        } else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of the element: ";
    cin >> n;

    int arr[n];
    cout << "Enter the values of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int v;
    cout << endl << "Enter the val you want to search: ";
    cin >> v;

    int result = bSearch(arr, n, v);

    if(result != -1)
    {
        cout << endl << "Element " << v << " found at the index " << result << ".";
    } else
        cout << endl << "Element " << v << " not found\n";

    return 0;
}
