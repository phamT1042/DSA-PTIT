#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int devIn[1001];
string BFS_check_cycle_with_Kahn(int v) {
    queue<int> q;
    for (int i = 1; i <= v; i++)
        if (!devIn[i]) q.push(i);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for (int x : ke[u]) {
            devIn[x]--;
            if (!devIn[x]) q.push(x);
        }
    }
    if (cnt != v) return "YES";
    return "NO";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        for (int i = 1; i <= v; i++) {
            ke[i].clear();
            devIn[i] = 0;
        }
        while (e--) {
            int x,y; cin >> x >> y;
            ke[x].push_back(y);
            devIn[y]++;
        }
        cout << BFS_check_cycle_with_Kahn(v) << endl;
    }
}