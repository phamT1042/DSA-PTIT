#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int a[n], b[m];
        map<int, int> check;
        for (int &x : a) {
            cin >> x;
            check[x] = 1;
        }
        for (int &x : b) {
            cin >> x;
            if (check[x]) check[x] = 2;
        }
        for (auto it : check) cout << it.first << ' ';
        cout << endl;
        for (auto it : check) {
            if (it.second == 2) cout << it.first << ' ';
        }
        cout << endl;
    }
}