#include <iostream>
#include <vector>
#include <utility>

void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;

        // Find the index of the smallest element in the unsorted portion
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}