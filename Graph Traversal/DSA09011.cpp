#include<bits/stdc++.h>
using namespace std;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int countIsland(vector<int> a[], int n, int m) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                cnt++;
                a[i][j] = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    auto it = q.front(); q.pop();
                    for (int k = 0; k < 8; k++) {
                        int i1 = it.first + dx[k];
                        int j1 = it.second + dy[k];
                        if (i1 < n && i1 >= 0 && j1 < m && j1 >= 0) {
                            if (a[i1][j1]) {
                            	a[i1][j1] = 0;
                            	q.push({i1, j1});
                        	}
						}
                    }
                }
            }
        }
    }
    return cnt;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> a[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                a[i].push_back(x);
            }
		}
        cout << countIsland(a, n, m) << "\n"; 
    }
    return 0;
}