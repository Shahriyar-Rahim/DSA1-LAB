#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int small = arr[i];
        int pos = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < small){
                small = arr[j];
                pos = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[pos];
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