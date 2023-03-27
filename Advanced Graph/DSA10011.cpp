#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int Dijkstra_Matrix (vector<int> a[], int n, int m) {
    int p[n][m], d[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            p[i][j] = 0;
            d[i][j] = INT_MAX;
        }
    p[0][0] = 1;
    d[0][0] = a[0][0];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {0, 0}});
    while (q.size()) {
        auto it = q.top(); q.pop();
        int i = it.second.first;
        int j = it.second.second;
        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m) {
                if (!p[i1][j1] && d[i1][j1] > d[i][j] + a[i1][j1]) {
                    d[i1][j1] = d[i][j] + a[i1][j1];
                    q.push({d[i1][j1], {i1, j1}});
                }
            }
        }
        p[i][j] = 1;
    }
    return d[n - 1][m - 1];
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                a[i].push_back(x);
            }
        cout << Dijkstra_Matrix(a, n, m) << endl;
    }
    return 0;
}