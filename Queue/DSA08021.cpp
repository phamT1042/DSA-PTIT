#include<bits/stdc++.h>
using namespace std;
int d[1001][1001], a[1001][1001];
int n, m;
bool solve() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    int down, right, i, j;
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        i = it.first; j = it.second;  
        down = i + a[i][j];
        right = j + a[i][j];
        if (down < n && !d[down][j]) {
            d[down][j] = d[i][j] + 1;
            if (down == n - 1 && j == m - 1) return true;
            else q.push({down, j});
        }
        if (right < m && !d[i][right]) {
            d[i][right] = d[i][j] + 1;
            if (i == n - 1 && right == m - 1) return true;
            else q.push({i, right});
        }
    }
    return false;
}
int main () {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> a[i][j];
        memset(d, 0, sizeof(d));
        if (solve()) cout << d[n - 1][m - 1];
        else cout << "-1";
        cout << endl;
    }
    return 0;
}
