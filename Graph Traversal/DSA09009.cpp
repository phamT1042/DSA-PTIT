#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int visited[1001];
int BFS_count (int v) {
    int tplt = 0;
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            tplt++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int point = q.front(); q.pop();
                for (int x : ke[point]) {
                    if (!visited[x]) {
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
            
        }
    }
    return tplt;
}
int main() {
    int T; cin >> T;
    while (T--) {
        flag = 0;
        int v, e, x, y; cin >> v >> e;
        while (e--) {
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        cout << BFS_count(v) << "\n";
        for (int i = 1; i < 1001; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}