#include <iostream>
using namespace std;

void patMat(string t, string p){
    bool found = false;
    for(int i = 0; i < t.length(); i++) {
        int c = 0;
        int j = 0;
        for(j; j < p.length(); j++) {
            if(p[j] == t[i + j]){
                c++;
            }
        }

        if(c == p.length()){
            cout << "found at index " << i << " " << endl;
            found = true;
        }
    }

    if(!found){
        cout << "Pattern does not found in the text" << endl;
    }
}

int main() {
    string t, p;

    cin >> t >> p;

    patMat(t, p);
    
    return 0;
}