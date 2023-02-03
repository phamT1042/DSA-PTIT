#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int dem[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            dem[x]++;
        }
        for (int i = 0; i < 3; i++) {
            while (dem[i]--) cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}