#include <bits/stdc++.h>
using namespace std;
int n, bit[11];
void result() {
    cout << bit[0];
    for (int i = 1; i < n; i++)
        if (bit[i] != bit[i - 1]) cout << 1;
        else cout << 0;
    cout << ' ';
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        bit[i] = j;
        if (i == n - 1) result();
        else Try(i + 1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        Try(0);
        cout << '\n';
    }
    return 0;
}