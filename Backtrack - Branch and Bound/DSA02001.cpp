#include<bits/stdc++.h>
using namespace std;
void result (int a[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << ' ';
    }
    cout << "]\n";
}
void Try (int a[], int n) {
    if (n == 0) return;
    result(a, n);
    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i] + a[i + 1];
    }
    Try(a, n - 1);
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        Try(a, n);
    }
}