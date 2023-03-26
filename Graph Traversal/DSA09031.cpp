#include<bits/stdc++.h>
using namespace std;
int visited[101][101];
set<pair<int, int>> pos_sheep;
set<pair<pair<int, int>, pair<int, int>>> pos_fence; 
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int n, k;
bool check (int i, int j, int i1, int j1) {
    if (i1 < 1 || i1 > n || j1 < 1 || j1 > n) return false;
    if (visited[i1][j1]) return false;
    if (pos_fence.find({{i1, j1}, {i, j}}) != pos_fence.end() || pos_fence.find({{i, j}, {i1, j1}}) != pos_fence.end()) return false;
    return true;
}
int BFS_move (int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    int sheep = 0;
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        if (pos_sheep.find({it.first, it.second}) != pos_sheep.end()) sheep++;
        for (int r = 0; r < 4; r++) {
            int i1 = it.first + dx[r];
            int j1 = it.second + dy[r];
            if (check(it.first, it.second, i1, j1)) {
                q.push({i1, j1});
                visited[i1][j1] = 1;
            } 
        }
    }
    return k - sheep;
}
int main () {
    int m, x, y, z, t; cin >> n >> k >> m;
    while (m--) {
        cin >> x >> y >> z >> t;
        pos_fence.insert({{x, y}, {z, t}});
    }
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        pos_sheep.insert({x, y});
    }
    int res = 0;
    for (auto it : pos_sheep) {
        visited[it.first][it.second] = 1;
        res += BFS_move(it.first, it.second);
        memset(visited, 0, sizeof(visited));
    }
    cout << res / 2;
    return 0;
}