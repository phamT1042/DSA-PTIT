#include<bits/stdc++.h>
using namespace std;
vector<int> ke[1001];
int parent[1001], visited[1001], End;
bool DFS_check_cycle (int u) {
    visited[u] = 1;
    for (int v : ke[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (DFS_check_cycle(v)) return true;
        }
        //Chú ý bước kiểm tra cung ngược (u, v): nó return true chỉ chứng tỏ rằng
        //tồn tại 1 chu trình trên đường đi xuất phát từ 1, cái ta cần là chu trình với 1 là đỉnh xuất phát => kết thúc tại 1
        //do đó ta cần thêm điều kiện điểm cuối cũng phải là 1 để cung ngược này tạo chu trình trở về 1
        else if (v != parent[u] && v == 1) {
            End = u;
            return true;
        }
    }
    return false;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        while (e--) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        for (int i = 1; i <= v; i++) sort(ke[i].begin(), ke[i].end());
        if (DFS_check_cycle(1)) {
            stack<int> path;
            path.push(1);
            while (End != 1) {
                path.push(End);
                End = parent[End];
            }
            path.push(End);
            while (!path.empty()) {
                cout << path.top() << ' ';
                path.pop();
            }
            
        }
        else cout << "NO";
        for (int i = 1; i <= v; i++) {
            visited[i] = 0;
            ke[i].clear();
            parent[i] = 0;
        }
        cout << '\n';
    }
}