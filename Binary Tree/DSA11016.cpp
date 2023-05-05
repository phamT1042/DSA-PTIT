#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> res;
        while (n--) {
            int x, y; char z;
            cin >> x >> y >> z;
            res.insert(x);
            res.insert(y);
        }
        for (int x : res) cout << x << ' ';
        cout << '\n';
    }
}