#include <bits/stdc++.h>
using namespace std;
int n, a[17];
void result() {
    if (a[0] == 0 || a[n - 1] == 1) return;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 1 && a[i + 1] == 1) return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i]) cout << "H";
        else cout << "A";
    }
    cout << endl;
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n - 1) result ();
        else Try (i + 1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        Try(0);
    }
    return 0;
}