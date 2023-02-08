#include<bits/stdc++.h>
using namespace std;
int n, k, a[11], sh[11];
stack<string> res;
void result() {
    string s = "[";
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * sh[i];
        if (sum > k) return;
        if (sh[i])
            s += to_string(a[i]) + ' ';
    }
    if (sum == k) {
        s.erase(s.length() - 1, 1);
        res.push(s + "]");
    }
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        sh[i] = j;
        if (i == n - 1) result();
        else Try(i + 1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        Try(0);
        if (res.size()) {
            while (!res.empty()) {
                cout << res.top() << ' ';
                res.pop();
            }
        }
        else cout << "-1";
        cout << "\n";
    }
}