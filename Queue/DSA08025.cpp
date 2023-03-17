#include<bits/stdc++.h>
using namespace std;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int BFS (int s1, int s2, int e1, int e2) {
    int d[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) d[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({s1, s2});
    while (!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int next1 = tmp.first + dx[i];
            int next2 = tmp.second + dy[i];
            if (next1 == e1 && next2 == e2) return d[tmp.first][tmp.second] + 1;
            else {
                if (next1 < 9 && next1 > 0 && next2 > 0 && next2 < 9) {
                    if (!d[next1][next2]) {
                        d[next1][next2] = d[tmp.first][tmp.second] + 1;
                        q.push({next1, next2});
                    }
                }
            }
        }
    }
    return 0;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s1, s2; cin >> s1 >> s2;
        if (s1 == s2) cout << "0\n";
        else { 
            int starti, startj, endi, endj;
            starti = s1[0] - 'a' + 1;
            startj = s1[1] - '0';
            endi = s2[0] - 'a' + 1;
            endj = s2[1] - '0';
            cout << BFS(starti, startj, endi, endj) << endl;
        }
    }
}