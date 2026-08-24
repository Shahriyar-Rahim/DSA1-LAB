#include <iostream>
using namespace std;

void insertEl(int arr[], int &n, int val, int pos)
{

    cout << "\nTHe elements of the given array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (pos < 0 || pos > n)
    {
        cout << "Invalid Operation\n";
        return;
    }
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    n++;
    cout << "Element " << val << " iserted successfully at the index " << pos << endl;
    cout << "THe elements of the new array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "ENter the size of the array: ";
    cin >> n;
    int m;
    cout << "Enter the max size of the aray: ";
    cin >> m;
    int arr[m];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int v, p;
    cout << "Enter the value u wnat to insert: ";
    cin >> v;
    cout << "and where is the position for it: ";
    cin >> p;

    insertEl(arr, n, v, p);

    return 0;
}