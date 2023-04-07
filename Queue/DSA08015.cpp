#include<bits/stdc++.h>
using namespace std;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char box[31][31][31];
int a, b, c;
struct pos {
    int i, j, k;
};
int BFS (pos start) {
    queue<pair<int, pos>> q;
    q.push({0, start});
    box[start.i][start.j][start.k] = '#';
    while(q.size()) {
        auto it = q.front(); q.pop();
        int i = it.second.i;
        int j = it.second.j;
        int z = it.second.k;
        for (int k = 0; k < 6; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            int z1 = z + dz[k];
            if (i1 >= 0 && i1 < a && j1 >= 0 && j1 < b && z1 >= 0 && z1 < c) {
                if (box[i1][j1][z1] == '.') {
                    pos next;
                    next.i = i1;
                    next.j = j1;
                    next.k = z1;
                    q.push({it.first + 1, next});
                    box[i1][j1][z1] = '#';
                }
                else if (box[i1][j1][z1] == 'E') return 1 + it.first;
            }
        }
    } 
    return -1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        pos start;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> box[i][j][k];
                    if (box[i][j][k] == 'S') {
                        start.i = i;
                        start.j = j;
                        start.k = k;
                    }
                }
            }
        }
        cout << BFS(start) << '\n';
    }
    return 0;
}