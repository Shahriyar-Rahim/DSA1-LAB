#include <iostream>
#include <vector>
using namespace std;

int lSvector(const vector<int> &vec)
{
    cout << "Elements of the vector: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    int t;
    cout << "Which element you want to search: ";
    cin >> t;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == t)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> v;

    int n;
    cout << "Enter how many elements you want to insert: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;      
        v.push_back(val);
    }

    int result = lSvector(v);

    if (result == -1)
    {
        cout << "Element does not exist\n";
    }
    else
    {
        cout << "Found at index " << result << endl;
    }

    return 0;
}