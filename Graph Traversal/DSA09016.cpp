#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
//visited = 0 nếu đỉnh chưa từng được duyệt, = 1 nếu đang duyệt, = 2 nếu đã duyệt xong
int DFS_check_cycle (int u) {
    visited[u] = 1;
    for (int v : ke[u]) {
        if (!visited[v]) {
            if (DFS_check_cycle(v)) return true;
        }
        else if (visited[v] == 1) return true;
    }
    visited[u] = 2;
    return false;
}
string check (int v) {
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            if (DFS_check_cycle(i, 0)) return "YES";
        }
    }
    return "NO";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        for (int i = 1; i <= v; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
        while (e--) {
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
        }
        cout << check(v) << endl;
    }
}