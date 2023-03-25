#include<bits/stdc++.h>
using namespace std;
int visited[1001];
vector<int> ke[1001];
set<int> resPos, resPos_element;
//Tạo danh sách các vị trí có thể đến của người đầu tiên
void DFS_first (int u) {
    visited[u] = 1;
    resPos.insert(u);
    for (int v : ke[u]) {
        if (!visited[v]) DFS_first(v);
    }
}
//Tạo danh sách con các vị trí có thể đến từ người 2 trở đi
void DFS (int u) {
    visited[u] = 1;
    resPos_element.insert(u);
    for (int v : ke[u]) {
        if (!visited[v]) DFS(v);
    }
}
int main () {
    int k, n, m; cin >> k >> n >> m;
    int pos[k];
    for (int &x : pos) cin >> x;
    while (m--) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
    DFS_first(pos[0]);
    for (int i = 1; i < k; i++) {
        memset(visited, 0, sizeof(visited));
        resPos_element.clear();
        DFS(pos[i]);
        vector<int> delete_Pos;
        for (int x : resPos) {
            //Loại các vị trí người 1 đến được nhưng người thứ 2 về sau không thể đến
            if (resPos_element.find(x) == resPos_element.end()) {
                delete_Pos.push_back(x);
            }
        }
        for (int x : delete_Pos) resPos.erase(x);
    }
    cout << resPos.size();
    return 0;
}