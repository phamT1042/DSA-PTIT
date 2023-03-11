#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long a[n];
        long long Smax = 0;
        for (long long &x : a) cin >> x;
        stack<long long> dt;
        dt.push(0);
        for (int i = 1; i < n; i++) {
            while (a[i] < a[dt.top()]) {
                int idx = dt.top(); dt.pop();
                if (dt.empty()) {
                    Smax = max(Smax, i * a[idx]);
                    break;
                }
                else Smax = max(Smax, a[idx] * (i - dt.top() - 1));
            }
            dt.push(i);
        }
        while (!dt.empty()) {
            int idx = dt.top(); dt.pop();
            if (dt.empty()) Smax = max(Smax, n * a[idx]);
            else Smax = max(Smax, a[idx] * (n - dt.top() - 1));
        }
        cout << Smax << endl;
    }
}