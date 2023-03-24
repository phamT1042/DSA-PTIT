#include<bits/stdc++.h>
using namespace std;
int a[12], visited[12];
vector<int> ke[12];
int v;
bool Try_Hamilton_path(int i) {
    for (int j : ke[a[i - 1]]) {
        if (!visited[j]) {
            a[i] = j;
            visited[j] = 1;
            if (i == v) return true;
            else if (Try_Hamilton_path(i + 1)) return true;
            visited[j] = 0;
        }
    }
    return false;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int e; cin >> v >> e;
        while (e--) {
            int x, y; cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int flag = 0;
        for (int i = 1; i <= v; i++) {
            a[1] = i;
            memset(visited, 0, sizeof(visited));
            visited[i] = 1;
            if (Try_Hamilton_path(2)) {
                cout << "1\n";
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "0\n";
        for (int i = 1; i <= v; i++) ke[i].clear();
        memset(visited, 0, sizeof(visited));
    }
}