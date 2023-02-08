#include <bits/stdc++.h>
using namespace std;
int n, bit[11], gray[11];
void result() {
    for (int i = 1; i < n; i++) {
        if (bit[i] != bit[i - 1]) gray[i] = 1;
        else gray[i] = 0;
    }
    gray[0] = bit[0];
    for (int i = 0; i < n; i++) cout << gray[i];
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
        cout << endl;
    }
    return 0;
}