#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
string BFS_path(vector<char> a[], int n, int m, pair<int, int> S, pair<int, int> T) {
    //p[i][j].first: Trạng thái hiện tại khi di chuyển đến ô [i][j]:
    //left = 0, up = 1, down = 2, right = 3
    //p[i][j].second: Số lần đổi hướng khi di chuyển đến ô [i][j]
    pair<int, int> p[n][m];
    int visited[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0;
            p[i][j].first = p[i][j].second = 0;
        }
    }
    queue<pair<int, int>> q;
    visited[S.first][S.second] = 1;
    //Khởi tạo các ô cạnh S
    for (int i = 0; i < 4; i++) {
        int i1 = S.first + dx[i];
        int j1 = S.second + dy[i];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m) {
            if (a[i1][j1] != '*') {
                p[i1][j1] = {i, 0};
                q.push({i1, j1});
            } 
        }
    }
    while (q.size()) {
        auto it = q.front(); q.pop();
        int i = it.first;
        int j = it.second;
        if (i == T.first && j == T.second && p[i][j].second <= 2) return "YES";
        //Nếu ô hiện tại đã thăm hoặc số lần đổi hướng để đến đây lớn hơn 2 thì bỏ qua
        if (visited[i][j] || p[i][j].second > 2) continue;
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m) {
                if (a[i1][j1] != '*') {
                    q.push({i1, j1});
                    //Nếu hướng đến ô tiếp theo khác hướng ô hiện tại, số lần đổi hướng +1
                    if (k != p[i][j].first) p[i1][j1] = {k, p[i][j].second + 1};
                    else p[i1][j1] = {k, p[i][j].second};
                } 
            }
        }
    }
    return "NO";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<char> a[n];
        pair<int, int> S, T;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x; cin >> x;
                a[i].push_back(x);
                if (x == 'S') S = {i, j};
                else if (x == 'T') T = {i, j};
            }
        }
        cout << BFS_path(a, n, m, S, T) << '\n';
    }
}