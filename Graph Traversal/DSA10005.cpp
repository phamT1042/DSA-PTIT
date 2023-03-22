#include<bits/stdc++.h>
using namespace std;
int devOut[1001], devIn[1001];

int checkEuler (int v) {
    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (devOut[i] != devIn[i]) return 0;
    }
    return 1;
}
int main() {
    int T; cin >> T;
    while (T--) {
        int v, e, x, y; cin >> v >> e;
        while (e--) {
            cin >> x >> y;
            devOut[x]++; devIn[y]++;
        }
        cout << checkEuler(v) << "\n";
        memset(devOut, 0, sizeof(devOut));
        memset(devIn, 0, sizeof(devIn));
    }
    return 0;
}