#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string bit; cin >> bit;
        cout << bit[0];
        for (int i = 1; i < bit.length(); i++) 
            if (bit[i] != bit[i - 1]) cout << 1;
            else cout << 0;
        cout << '\n';
    }
    return 0;
}