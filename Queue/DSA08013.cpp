#include<bits/stdc++.h>
using namespace std;
char a[101][101];
int n, d[101][101];
bool solve(int si, int sj, int ei, int ej) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    int i, j;
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        i = it.first; j = it.second;
        for (int k = i + 1; k < n; k++) {
            if (k == si && j == sj) continue;
            if (a[k][j] == 'X') break;
            if (!d[k][j]) {
                d[k][j] = d[i][j] + 1;
                if (k == ei && j == ej) return true;
                else q.push({k, j});
            }
        }
        for (int k = i - 1; k >= 0; k--) {
            if (k == si && j == sj) continue;
            if (a[k][j] == 'X') break;
            if (!d[k][j]) {
                d[k][j] = d[i][j] + 1;
                if (k == ei && j == ej) return true;
                else q.push({k, j});
            }
        }
        for (int k = j + 1; k < n; k++) {
            if (k == si && j == sj) continue;
            if (a[i][k] == 'X') break;
            if (!d[i][k]) {
                d[i][k] = d[i][j] + 1;
                if (i == ei && k == ej) return true;
                else q.push({i, k});
            }
        }
        for (int k = j - 1; k >= 0; k--) {
            if (k == si && j == sj) continue;
            if (a[i][k] == 'X') break;
            if (!d[i][k]) {
                d[i][k] = d[i][j] + 1;
                if (i == ei && k == ej) return true;
                else q.push({i, k});
            }
        }
    }
    return false;
}
int main () {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];
        memset(d, 0, sizeof(d));
        int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
        if (solve(i1, j1, i2, j2)) cout << d[i2][j2];
        else cout << "-1";
        cout << endl;
    }
    return 0;
}
