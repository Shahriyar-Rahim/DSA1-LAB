#include<iostream>
using namespace std;

void isEl(int arr[], int &n, int v, int p)
{
    cout << "The element of the array before inserting: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if(p < 0 || p > n)
    {
        cout << "Invalid Operation\n";
        return;
    }

    for(int i=n; i > p; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[p] = v;
    n++;

    cout << "Successfully inserted " << v << " at the index " << p << ".\n";

    cout << "The element of the array after inserting: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int n, m;
    cout << "Enter the size of the element: ";
    cin >> n;
    cout << "Enter the max size of the array: ";
    cin >> m;

    int arr[m];
    cout << "Enter the values of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int v, p;
    cout << "Enter the val and the position where you want to insert: ";
    cin >> v >> p;

    isEl(arr, n, v, p);

    return 0;
}
