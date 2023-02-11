#include<bits/stdc++.h>
using namespace std;
int n, m, res, cnt;
bool mtKe[21][21]; //Ma trận kề để lưu các cạnh
vector<int> ke[21]; //danh sách kề lưu các đỉnh kề với i: ke[i]
void DFS (int u) {
    res = max(cnt, res);
    for (int x : ke[u]) {
        if (!mtKe[u][x]) {
            mtKe[u][x] = mtKe[x][u] = true;
            cnt++;
            DFS(x);
            cnt--;
            mtKe[u][x] = mtKe[x][u] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        res = INT_MIN;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            memset(mtKe, false, sizeof(mtKe));
            DFS(i);
        }
        cout << res << endl;
        for (int i = 0; i < n; i++) {
            ke[i].clear();
        }
    }
}