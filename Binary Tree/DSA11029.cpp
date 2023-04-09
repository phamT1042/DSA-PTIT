#include<bits/stdc++.h>
using namespace std;
int parent[1001], visited[1001];
vector<int> child[1001];
vector<int> Leaf_Node;
void DFS (int u) {
    visited[u] = 1;
    if (child[u].size() == 0) Leaf_Node.push_back(u);
    else {
        for (int v : child[u]) {
            parent[v] = u; 
            DFS(v);
        }
    }
}
int main () {
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n;
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            child[x].push_back(y);
        }
        DFS(1);
        sort(Leaf_Node.begin(), Leaf_Node.end());
        for (int x : Leaf_Node) {
            vector<int> way;
            while (x != 1) {
                way.push_back(x);
                x = parent[x];
            }
            cout << 1 << ' ';
            for (int i = way.size() - 1; i >= 0; i--) 
                cout << way[i] << ' ';
            cout << '\n';
        }
        for (int i = 1; i <= n; i++) {
            parent[i] = visited[i] = 0;
            child[i].clear();
        }
        Leaf_Node.clear();
    }
    return 0;
}