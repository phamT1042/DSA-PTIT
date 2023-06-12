#include<bits/stdc++.h>
using namespace std;
//Đồ thị n đỉnh là cây nếu có tồn tại n - 1 cạnh và liên thông
vector<int> ke[1001];
int visited[1001];
void DFS (int u) {
    visited[u] = 1;
    for (int v : ke[u])
        if (!visited[v]) DFS(v);
}
string check (int n) {
    for (int i = 1; i <= n; i++) 
        if (!visited[i]) return "NO";
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
        DFS(1);
        cout << check(n) << endl;
        for (int i = 1; i <= n; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
    }
}