#include<iostream>
using namespace std;

void binarySearch(int arr[], int n, int t){
    bool found = false;

    int low = 0, high = n - 1;
    int mid = -1;
    for(; low<= high;) {
        mid = low + (high - low) / 2;
        if(t == arr[mid]){
          found = true;
            break;
        }
        if(t > arr[mid])
            low = mid + 1;
        else 
            high = mid - 1;
    }

    if(!found) {
        cout << "Target " << t << " is not preset in this dataset" << endl;
    }
    else 
        cout << "Target " << t << " found at the index " << mid << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int t;
    cin >> t;

    binarySearch(arr, n, t);

    return 0;
}