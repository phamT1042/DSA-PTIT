#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int a[n], b[m], c[k];
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        for (int &x : c) cin >> x;
        int i = 0, j = 0, h = 0;
        vector<int> res;
        while (i < n && j < m && h < k) {
            if (a[i] == b[j] && b[j] == c[h]) {
                res.push_back(a[i]);
                i++; j++; h++;
            }
            if (a[i] < b[j]) i++;
            if (b[j] < c[h]) j++;
            if (c[h] < a[i]) h++;
        }
        if (res.size()) for (int x : res) cout << x << ' ';
        else cout << "NO";
        cout << "\n";
    }
}