#include<bits/stdc++.h>
using namespace std;
int dev[1001];

int checkEuler (int v) {
    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (dev[i] % 2 == 1) cnt++;
    }
    if (cnt == 2) return 1;
    else if (cnt == 0) return 2;
    return 0;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int v, e, x, y; cin >> v >> e;
        while (e--) {
            cin >> x >> y;
            dev[x]++; dev[y]++;
        }
        cout << checkEuler(v) << "\n";
        memset(dev, 0, sizeof(dev));
    }
    return 0;
}