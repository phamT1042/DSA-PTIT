#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string bit; cin >> bit;
        char gray[bit.length()];
        for (int i = 1; i < bit.length(); i++) {
            if (bit[i] != bit[i - 1]) gray[i] = '1';
            else gray[i] = '0';
        }
        gray[0] = bit[0];
        for (int i = 0; i < bit.length(); i++) {
            cout << gray[i];
        }
        cout << endl;
    }
    return 0;
}