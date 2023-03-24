#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[101][101]; //ma tran trong so toi da 100 dinh tu 1 -> 100
void input() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) a[i][j] = 1e9;
    while (m--) {
        int x, y, z; cin >> x >> y >> z;
        a[x][y] = z;
        a[y][x] = z;
    }
}
void Floyd() {
    int d[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = a[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        cout << d[x][y] << endl;
    }
}
int main() {
    input();
    Floyd();
    return 0;
}