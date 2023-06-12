#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> a[], int n, int m) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    int down, right, i, j;
    int vs[n][m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) vs[i][j] = 0;
    vs[0][0] = 1;
    while (q.size()) {
        auto it = q.front(); q.pop();
        pair<int, int> vt = it.first;
        int d = it.second;
        i = vt.first; j = vt.second;
        down = i + a[i][j];
        right = j + a[i][j];
        if (down < n && !vs[down][j]) {
            if (down == n - 1 && j == m - 1) return d + 1;
            vs[down][j] = 1;
            q.push({{down, j}, d + 1});
        }
        if (right < m && !vs[i][right]) {
            if (i == n - 1 && right == m - 1) return d + 1;
            vs[i][right] = 1;
            q.push({{i, right}, d + 1});
        }
    }
    return -1;
}
int main () {
    int t; cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m;
        vector<int> a[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x; a[i].push_back(x);
            }
        }
        cout << solve(a, n, m) << '\n';
    }
    return 0;
}
