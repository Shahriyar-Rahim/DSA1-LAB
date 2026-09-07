#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

int main(){
    int n;
    cout << "ENter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int t;
    cout << "Enter the element to search: ";
    cin >> t;

    auto it = find(arr, arr+n, t);

    if(it != arr + n){
        int idex = distance(arr, it);
        cout << "Element " << t << " found at index " << idex << endl;
    } else {
        cout << "Element " << t << " not found" << endl;
    }

    return 0;
}