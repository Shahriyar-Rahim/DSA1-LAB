#include <iostream>
#include <vector>
#include <utility> // for std::swap

void optimizedBubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;

        // Inner loop decreases boundary by i since the last i elements are already sorted
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, array is sorted
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    optimizedBubbleSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}