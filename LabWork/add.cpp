#include<iostream>
using namespace std;

int main()
{
    int r,c;
    cout <<"ENter row and column respectively: ";
    cin >> r >> c;

    int a[r][c];
    cout << "Enter the elements of first matrix: ";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << "Enter the values for a matrix[" << i << "]["<< j << "]: ";
            cin >> a[i][j];
        }
        cout << endl;
    }

    int b[r][c];
    cout << "Enter the elements of ssecond matrix: ";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << "Enter the values for a matrix[" << i << "]["<< j << "]: ";
            cin >> b[i][j];
        }
        cout << endl;
    }

    int s[r][c];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            s[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "B matrix is:\n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "B matrix is:\n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "The resultant matrix is:\n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
