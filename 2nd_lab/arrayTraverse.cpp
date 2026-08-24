#include<iostream>
using namespace std;

void arrayTraverse(int arr[], int n) {
    cout << "\nTHe elements of the given array is: ";
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "ENter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    arrayTraverse(arr, n);

    return 0;
}