#pragma GCC optimize("O3", "fast-math", "unroll-loops")
#pragma GCC target("avx2")
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> paii;
int n, m;
vector<pair<paii, paii>> rao;
vector<paii> bo;
int vs[2005][2005];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int mx = 0;

bool cmp (vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

void CoordinateCompression() {
    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        a.push_back({rao[i].first.first, i, 1, 1}); //{toa do x/y, thu tu rao, x/y diem 1, x/y diem2}
        a.push_back({rao[i].first.second, i, 1, 2}); 
        a.push_back({rao[i].second.first, i, 2, 1});
        a.push_back({rao[i].second.second, i, 2, 2});
    }
    for (int i = 0; i < m; i++) {
        a.push_back({bo[i].first, i, 1});
        a.push_back({bo[i].second, i, 2});
    }
    sort(a.begin(), a.end(), cmp);

    int start = 0;
    if (a[0].size() == 4) {
        if (a[0][2] == 1) {
            if (a[0][3] == 1) 
                rao[a[0][1]].first.first = start;
            else 
                rao[a[0][1]].first.second = start;
        }
        else {
            if (a[0][3] == 1) 
                rao[a[0][1]].second.first = start;
            else 
                rao[a[0][1]].second.second = start;
        }
    }
    else {
        if (a[0][2] == 1) bo[a[0][1]].first = start;
        else bo[a[0][1]].second = start;
    }

    for (int i = 1; i < a.size(); i++) {
        if (a[i][0] != a[i - 1][0]) {
            start += 1;
            mx = start;
        }
        if (a[i].size() == 4) {
            if (a[i][2] == 1) {
                if (a[i][3] == 1) 
                    rao[a[i][1]].first.first = start;
                else 
                    rao[a[i][1]].first.second = start;
            }
            else {
                if (a[i][3] == 1) 
                    rao[a[i][1]].second.first = start;
                else 
                    rao[a[i][1]].second.second = start;
            }
        }
        else {
            if (a[i][2] == 1) bo[a[i][1]].first = start;
            else bo[a[i][1]].second = start;
        }
    } 

}
void HangRaoVaBo() {
    for (auto it : rao) {
        int x1 = it.first.first;
        int y1 = it.first.second;
        int x2 = it.second.first;
        int y2 = it.second.second;
        if (vs[x1][y1] == 0) vs[x1][y1] = -1; //1 đầu rào chưa giao nhau
        else vs[x1][y1] = 1; //điểm rào giao/trên rào           
        if (vs[x2][y2] == 0) vs[x2][y2] = -1; 
        else vs[x2][y2] = 1;
        if (x1 == x2) {
            if (y1 < y2) 
                for (int i = y1 + 1; i < y2; i++) vs[x1][i] = 1;           
            else 
                for (int i = y2 + 1; i < y1; i++) vs[x1][i] = 1;
        }
        else {
            if (x1 < x2) 
                for (int i = x1 + 1; i < x2; i++) vs[i][y1] = 1;
            else 
                for (int i = x2 + 1; i < x1; i++) vs[i][y1] = 1;
        }
    }
    for (auto it : bo) 
        vs[it.first][it.second] = 2;
}
int bfs (paii bo) {
    vs[bo.first][bo.second] = 1;
    int cnt = 1;
    queue<paii> q; q.push(bo);
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        int i = it.first, j = it.second;
        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (i1 >= 0 && j1 >= 0 && i1 <= mx + 5 && j1 <= mx + 5 && vs[i1][j1] != 1) {
                if (vs[i1][j1] == 2) cnt++;
                vs[i1][j1] = 1;
                q.push({i1, j1});
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y, z, t; cin >> x >> y >> z >> t;
        rao.push_back({{x, y}, {z, t}});
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        bo.push_back({x, y});
    }
    CoordinateCompression();
    HangRaoVaBo();
    int res = 0;
    for (auto it : bo) 
        if (vs[it.first][it.second] != 1) res = max(res, bfs(it));
    cout << res;
    return 0;
}
