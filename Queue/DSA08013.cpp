#include<bits/stdc++.h>
using namespace std;
int solve(int si, int sj, int ei, int ej, int n, vector<char> a[]) {
    queue<pair<pair<int, int>, int>> q;
    int vs[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) vs[i][j] = 0;
    q.push({{si, sj}, 0});
    vs[si][sj] = 1;
    int i, j, k, d;
    while (q.size()) {
        auto it = q.front(); q.pop();
        i = it.first.first; j = it.first.second;
        d = it.second;
        k = i + 1;
        while (k < n && a[k][j] == '.') {
            if (!vs[k][j]) {
                if (k == ei && j == ej) return d + 1;
                vs[k][j] = 1;
                q.push({{k, j}, d + 1});
            }
            k++;
        }
        k = i - 1;
        while (k >= 0 && a[k][j] == '.') {
            if (!vs[k][j]) {
                if (k == ei && j == ej) return d + 1;
                vs[k][j] = 1;
                q.push({{k, j}, d + 1});
            }
            k--;
        }
        k = j + 1;
        while (k < n && a[i][k] == '.') {
            if (!vs[i][k]) {
                if (i == ei && k == ej) return d + 1;
                vs[i][k] = 1;
                q.push({{i, k}, d + 1});
            }
            k++;
        }
        k = j - 1;
        while (k >= 0 && a[i][k] == '.') {
            if (!vs[i][k]) {
                if (i == ei && k == ej) return d + 1;
                vs[i][k] = 1;
                q.push({{i, k}, d + 1});
            }
            k--;
        }
    }
    return -1;
}
int main () {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<char> a[n]; char x;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) {
                cin >> x; a[i].push_back(x);
            }
        int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
        cout << solve(i1, j1, i2, j2, n, a) << '\n';
    }
    return 0;
}
