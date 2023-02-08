#include<bits/stdc++.h>
using namespace std;
stack<string> res;
void result (int a[], int n) {
    string s = "[";
    for (int i = 0; i < n; i++) {
        s += to_string(a[i]);
        if (i < n - 1) s += " ";
    }
    s += "]";
    res.push(s);
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
        while (!res.empty()) {
            cout << res.top() << ' ';
            res.pop();
        }
        cout << endl;
    }
}