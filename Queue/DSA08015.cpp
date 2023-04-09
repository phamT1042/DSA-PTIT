#include<bits/stdc++.h>
using namespace std;
int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};
char box[31][31][31];
int a, b, c;
struct pos {
    int x, y, z;
};
int BFS (pos start) {
    queue<pair<int, pos>> q;
    q.push({0, start});
    box[start.z][start.y][start.x] = '#';
    while(q.size()) {
        auto it = q.front(); q.pop();
        int z = it.second.z;
        int y = it.second.y;
        int x = it.second.x;
        for (int k = 0; k < 6; k++) {
            int z1 = z + dz[k];
            int y1 = y + dy[k];
            int x1 = x + dx[k];
            if (z1 >= 0 && z1 < a && y1 >= 0 && y1 < b && x1 >= 0 && x1 < c) {
                if (box[z1][y1][x1] == '.') {
                pos next;
                next.z = z1;
                next.y = y1;
                next.x = x1;
                q.push({it.first + 1, next});
                box[z1][y1][x1] = '#';
            }
            else if (box[z1][y1][x1] == 'E') return 1 + it.first;
        }
            
        }
    } 
    return -1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> a >> b >> c; //a la truc Oz, b la Oy, c la Ox
        pos start;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> box[i][j][k];
                    if (box[i][j][k] == 'S') {
                        start.z = i;
                        start.y = j;
                        start.x = k;
                    }
                }
            }
        }
        cout << BFS(start) << '\n';
    }
    return 0;
}