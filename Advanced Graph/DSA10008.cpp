#include<bits/stdc++.h>
using namespace std;

int n, m, s;
vector<pair<int, int>> ke[1001]; //Các đỉnh second kề với i với trọng số cạnh first
void input() {
    cin >> n >> m >> s;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        ke[a].push_back({c, b});
        ke[b].push_back({c, a});
    }
}
void Dijkstra() {
    vector<int> d(n + 1, INT_MAX);
    vector<bool> P(n + 1, false);
    d[s] = 0;
    P[s] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        pair<int, int> tmp = q.top(); q.pop();
        for (pair<int, int> it : ke[tmp.second]) {
            int v = it.second;
            int w = it.first;
            if (!P[v] && d[v] > d[tmp.second] + w) {
                d[v] = d[tmp.second] + w;
                q.push({d[v], v});
            }
        }
        P[tmp.second] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] != INT_MAX) cout << d[i] << ' ';
        else cout << "-1";
    }
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        input();
        Dijkstra();
        for (int i = 1; i <= n; i++) ke[i].clear();
    }
    return 0;
}