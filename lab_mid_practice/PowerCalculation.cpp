#include <iostream>
using namespace std;

int pcalc(int b, int e) {
    int r = 1;

    for(int i = 1; i <= e; i++){
        r *= b;
    }

    return r;
}

int main() {
    int b, e;

    cin >> b >> e;

    int result = pcalc(b, e);

    cout << result << endl;
    
    return 0;
}