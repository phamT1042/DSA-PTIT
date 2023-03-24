#include<bits/stdc++.h>
using namespace std;
//Đồ thị n đỉnh là cây nếu có tồn tại n - 1 cạnh và không chứa chu trình
vector<int> ke[1001];
int visited[1001];
bool DFS_check_cycle (int u, int parent_u) {
    visited[u] = 1;
    for (int v : ke[u]) {
        if (!visited[v]) {
            if (DFS_check_cycle(v, u)) return true;
        }
        else if (v != parent_u) return true;
    }
    return false;
}
string check (int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            if (DFS_check_cycle(i, 0)) return "NO";
    }
    return "YES";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        cout << check(n) << endl;
        for (int i = 1; i <= n; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
    }
}