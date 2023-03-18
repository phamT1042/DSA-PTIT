#include<bits/stdc++.h>
using namespace std;
int a[501][501];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

struct pos {
    int i, j;
};
queue<pair<pos, int>> q;
int spread (int r, int c, vector<int> a[]) {
    int res = 0;
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        pos tmp = it.first;
        int day = it.second, nexti, nextj;
        for (int k = 0; k < 4; k++) {
            nexti = tmp.i + dx[k];
            nextj = tmp.j + dy[k];
            if (nexti < r && nexti >= 0 && nextj < c && nextj >= 0 && a[nexti][nextj] == 1) {
                a[nexti][nextj] = 2;
                pos add; add.i = nexti; add.j = nextj;
                q.push({add, day + 1});
                res = max(res, day + 1);
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 1) return -1;
        }
    }
    return res;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int r, c, x; cin >> r >> c;
        vector<int> a[r];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> x;
                a[i].push_back(x);
                if (a[i][j] == 2) {
                    pos tmp;
                    tmp.i = i; tmp.j = j;
                    q.push({tmp, 0});
                }
            }
        }
        cout << spread(r, c, a) << endl;
    }
}