#include <iostream>
using namespace std;

void lSearch(int arr[], int n, int target)
{

    cout << "\nTHe elements of the given array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            pos = i;
        }
    }

    if (pos == -1)
    {
        cout << "Element " << target << " does not exists here\n";
        return;
    }

    cout << "Element " << target << " found at the index " << pos << endl;
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

    int p;
    cout << "Inter the element to search: ";
    cin >> p;

    lSearch(arr, n, p);

    return 0;
}