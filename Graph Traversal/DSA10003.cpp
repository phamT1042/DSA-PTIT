#include<bits/stdc++.h>
using namespace std;
//Để kiểm tra đồ thị vô hướng này có chu trình hay không thì ở bước union_set đối với 2
//đỉnh của 1 cạnh trong đồ thị (thêm cạnh mới), ta kiểm tra xem 2 đỉnh này có thuộc cùng 1 thành phần 
//liên thông hay không (cùng parent), nếu có thì cạnh đó tạo thành 1 chu trình trong đồ thị;
//nếu không thì hợp nhất cạnh đó vào tập hợp đồ thị đang xây dựng
int parent[1001];
void make_set (int v) {
    parent[v] = v;
}
int find_set (int v) {
    if (parent[v] == v) return v;
    return find_set(parent[v]);
}
bool union_set (int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;
    parent[b] = a;
    return false;
}
int main () {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        memset(parent, 0, sizeof(parent));
        vector<pair<int, int>> edge;
        for (int i = 1; i <= v; i++) make_set(i);
        while (e--) {
            int x, y; cin >> x >> y;
            edge.push_back({x, y});
        }
        int flag = 0;
        for (auto it : edge) {
            if (union_set(it.first, it.second)) {
                flag = 1;
                cout << "YES\n";
                break;
            }
        }
        if (!flag) cout << "NO\n";
    }
}