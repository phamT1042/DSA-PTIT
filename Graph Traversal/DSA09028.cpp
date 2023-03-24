#include<bits/stdc++.h>
using namespace std;

set<int> ke[1001];
int dev[1001];     //bậc của đinh i
bool color[1001];  //Kiểm tra đỉnh i đã được tô màu chưa
bool cmp (int a, int b) {
    return dev[a] > dev[b];
}
int GraphColoring (int v) {
    int cntColor = 0;
    int a[v + 1];
    for (int i = 0; i <= v; i++) a[i] = i;
    //B1: Lập danh sách là các đỉnh của đồ thị được sắp xếp theo thứ tự bậc giảm dần
    sort(a, a + v + 1, cmp);
    for (int i = 0; i < v; i++) {
        if (!color[a[i]]) {
            cntColor++;
            color[a[i]] = 1;
            //Tô màu i cho đỉnh đang xét nếu nó chưa được tô. Duyệt lần lượt các đỉnh khác và chỉ tô màu i cho các đỉnh không kề đỉnh đã có màu i.
            for (int j = i + 1; j < v; j++) {
                if (!color[a[j]] && ke[a[i]].find(a[j]) == ke[a[i]].end()) color[a[j]] = 1;
            }
        }
    }
    return cntColor;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int v, e, m; cin >> v >> e >> m;
        while (e--) {
            int x, y; cin >> x >> y;
            dev[x]++; dev[y]++;
            ke[x].insert(y);
            ke[y].insert(x);
        }
        if (GraphColoring(v) <= m) cout << "YES\n";
        else cout << "NO\n";
        memset(color, 0, sizeof(color));
        memset(dev, 0, sizeof(dev));
        for (int i = 1; i <= v; i++) ke[i].clear();
    }
}