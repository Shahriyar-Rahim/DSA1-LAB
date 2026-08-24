#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low+(high - low) / 2;
        if(arr[mid] == target)
            return mid;
        if(arr[mid] < target)
            low = mid + 1;
        else
        high = mid - 1;
    }

    return -1;
}

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

    int result = binarySearch(arr, n, p);
    
    if(result != 1){
        cout << "The element " << p << " found at the index " << result << endl;
    } else {
        cout << "Element " << p << " not found\n";
    }

    return 0;
}