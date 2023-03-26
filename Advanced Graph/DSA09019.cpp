#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001], parent[1001];
bool BFS_check_cycle (int u) {
    queue<int> q;
    q.push(u); visited[u] = 1;
    while (q.size()) {
        int v  = q.front(); q.pop();
        for (int x : ke[v]) {
            if (!visited[x]) {
                q.push(x); visited[x] = 1;
                parent[x] = v;
            }
            else if (x != parent[v]) return true;
        }
    }
    return false;
}
string check (int v) {
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            if (BFS_check_cycle(i)) return "YES";
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
        memset(parent, 0, sizeof(parent));
        while (e--) {
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        cout << check(v) << endl;
    }
}