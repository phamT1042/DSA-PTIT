#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int a[n], b[m];
        vector<int> res(n + m);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        sort(a, a + n); sort(b, b + m);
        auto it = set_union(a, a + n, b, b + m, res.begin());
        res.resize(it - res.begin());
        for (int x : res) cout << x << ' ';
        cout << '\n';
        it = set_intersection(a, a + n, b, b + m, res.begin());
        res.resize(it - res.begin());
        for (int x : res) cout << x << ' ';
        cout << '\n';
    }
}