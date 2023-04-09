#include<bits/stdc++.h>
using namespace std;
int BFS (int u, vector<int> child[]) {
    queue<pair<int, int>> q; 
    q.push({0, u});
    int height_tree = 0;
    while (q.size()) {
        auto tmp = q.front(); q.pop();
        if (child[tmp.second].size() == 0) height_tree = max(height_tree, tmp.first);
        else {
            for (int v : child[tmp.second])
                q.push({tmp.first + 1, v});
        }
    }
    return height_tree;
}
int main () {
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n;
        vector<int> child[n + 1];
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            child[x].push_back(y);
        }
        cout << BFS(1, child) << '\n';
    }
    return 0;
}