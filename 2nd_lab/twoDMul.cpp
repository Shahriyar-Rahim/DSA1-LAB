#include <iostream>
#include <iomanip>
using namespace std;

void multMat(int **a, int **b, int **res, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res[i][j] = a[i][j] * b[i][j];
        }
    }
}

void printRes(int **res, int r, int c)
{
    cout << "\nResultant Matrix:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << setw(4) << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int r, c;
    cout << "Enter the rows and cols of the matrix: ";
    cin >> r >> c;

    // Allocate rows (array of pointers)
    int **a = new int *[r];
    int **b = new int *[r];
    int **res = new int *[r];

    // Allocate columns for each row
    for (int i = 0; i < r; i++)
    {
        a[i] = new int[c];
        b[i] = new int[c];
        res[i] = new int[c];
    }

    cout << "Enter the elements of array a:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter the element [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "The elements of array a:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the elements of array b:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter the element [" << i << "][" << j << "]: ";
            cin >> b[i][j];
        }
    }

    cout << "The elements of array b:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    multMat(a, b, res, r, c);
    printRes(res, r, c);

    for (int i = 0; i < r; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] res[i];
    }
    delete[] a;
    delete[] b;
    delete[] res;

    return 0;
}