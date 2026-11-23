#include<iostream>
using namespace std;

class BubbleSort
{
    //int arr[];

public:
    BubbleSort();
    void operation();
    ~BubbleSort();
};


BubbleSort::BubbleSort()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void BubbleSort::operation()
{
    int i, count;
    bool swapped;
    for(i = 0; i < sizeof(arr) - 1; i++)
    {
        swapped = false;
        for(j = 0; j < sizeof(arr) - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
                swapped = true;
            }
        }

        if(!swapped) break;
    }

    cout << "Outer for loop runs " << i << " times"
         <<"\nInner for loop runs " << j << " times\n";
}

BubbleSort:: ~BubbleSort();

int main()
{

}
