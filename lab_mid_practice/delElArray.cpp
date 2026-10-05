#include <iostream>
using namespace std;

void delEl(int arr[], int n, int t){

    if (t < 0 || t >= n)
    {
        cout << "Invalid index for deletion" << endl;
        return;
    }

    for(int i = t; i < n -1; i++){
        arr[i]= arr[i+1];
    }
    n--;

    cout << "The updated array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int m,n, t;

    cin >> m >> n;

    int arr[m];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The original array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The indexes are       : ";
    for(int i = 0; i < n; i++) {

        cout << i << " ";
    }
    cout << endl;

    cin >> t;
    
    
    delEl(arr, n, t);

    return 0;
}