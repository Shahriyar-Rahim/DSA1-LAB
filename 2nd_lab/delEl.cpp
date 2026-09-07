#include <iostream>
using namespace std;

void dleEL(int arr[], int &n, int pos)
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

    int item = arr[pos];
    for (int i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element " << item << " deleted successfully at the index " << pos << endl;
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

    int p;
    cout << "Inter the position of the deleting item: ";
    cin >> p;

    dleEL(arr, n, p);

    return 0;
}