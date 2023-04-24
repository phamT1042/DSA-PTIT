#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        int d[v + 1][v + 1];
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++) {
                if (i == j) d[i][j] = 0;
                else d[i][j] = INT_MAX;
            }
        while (e--) {
            int x, y; cin >> x >> y;
            d[x][y] = 1;
        }
        for (int k = 1; k <= v; k++) {
            for (int i = 1; i <= v; i++) {
                for (int j = 1; j <= v; j++) {
                    if (d[i][k] != INT_MAX && d[k][j] != INT_MAX) {
                        if (d[i][j] > d[i][k] + d[k][j]) {
                            d[i][j] = d[i][k] + d[k][j];
                        }
                    }
                }
            }
        }
        int sumKC = 0, edge = 0;
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (d[i][j] != INT_MAX && i != j) {
                    edge++;
                    sumKC += d[i][j];
                }
            }
        }
        cout << fixed << setprecision(2) << (1.0f) * sumKC / edge << '\n';
    }
    return 0;
}