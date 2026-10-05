#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int a[n][n], b[n][n], r[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a [i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            r[i][j] = a[i][j] * b[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}