#include<iostream>
using namespace std;

int lSearch(int arr[], int n, int t)
{
    cout << "The element of the array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        if(t == arr[i])
        {
            return i;
        }
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
    cout << "Enter the val you want to search: ";
    cin >> v;

    int result = lSearch(arr, n, v);

    if(result != -1)
    {
        cout << "Element " << v << " found at the index " << result << ".";
    } else
        cout << "Element " << v << " not found\n";

    return 0;
}
