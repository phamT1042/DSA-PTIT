#include<bits/stdc++.h>
using namespace std;

//Giá trị dinh dưỡng tổng hợp được của node u = a[u] = (số lượng node con cháu của u) + (tổng gtdd tổng hợp được của các node con của u) + 1
vector<int> ke[200001];
long long a[200001], child[200001];
void DFS_spread (int u) {
    for (int v : ke[u]) {
        DFS_spread(v);
        //Cộng dồn số lượng node con cháu của v vào u tính cả v.
        child[u] += child[v] + 1;
        //Tổng gtdd tổng hợp được của node v
        a[u] += a[v];
    }
    //Cộng thêm số lương node con cháu của u
    a[u] += child[u];
}
int main () {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        ke[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = 1; 
        child[i] = 0;
    }
    DFS_spread(1);
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
}