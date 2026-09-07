#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        // Shift elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}