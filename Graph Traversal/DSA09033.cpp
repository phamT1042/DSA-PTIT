#include<bits/stdc++.h>
using namespace std;
vector<int> ke[100001];
int visited[100001];
int dev[100001];
//i là bạn của j, j là bạn của k thì i phải là bạn của k mới hoàn hảo
//=>Điều kiện hoàn hảo: Mọi đỉnh trong cùng 1 thành phần liên thông bất kì trong đồ thị phải có bậc bằng nhau
bool DFS_perfect (int u) {
    visited[u] = 1;
    for (int v : ke[u]) {
        if (!visited[v]) {
            if (dev[v] != dev[u]) return false;
            else if (!DFS_perfect(v)) return false;
        }
    }
    return true;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        while (e--) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
            dev[x]++; dev[y]++;
        }
        int flag = 1;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                if (!DFS_perfect(i)) {
                    cout << "NO\n";
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) cout << "YES\n";
        for (int i = 1; i <= v; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
        memset(dev, 0, sizeof(dev));
    }
}