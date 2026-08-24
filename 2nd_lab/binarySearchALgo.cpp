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

    int p;
    cout << "Inter the element to search: ";
    cin >> p;

    bool exists = binary_search(arr, arr + n, p);

    auto it = lower_bound(arr, arr+n, p);

    if(it != arr+n && *it == p){
        int ind = distance(arr, it);
        cout << "Element " << p << " found at index " << ind << endl;
    }
    else 
        cout << "Element " << p << " not found\n";

    return 0;
}