#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, x; cin >> n >> m;
        map<int, long long> cntX, cntY;
        while (n--) {
            cin >> x;
            cntX[x]++;
        }
        while (m--) {
            cin >> x;
            cntY[x]++;
        }
        long long res = 0;
        for (auto it : cntX) {
            if (it.first == 0) continue;
            res += cntY[0] * it.second;
            if (it.first == 1) continue;
            res += cntY[1] * it.second;
            if (it.first == 2) {
                for (auto x : cntY) {
                    if (x.first > 4) res += x.second * it.second;
                }
            }
            else if (it.first == 3) {
                res += cntY[2] * it.second;
                for (auto x : cntY) {
                    if (x.first > 3) res += x.second * it.second;
                }
            }
            else {
                for (auto x : cntY) {
                    if (x.first > it.first) res += x.second * it.second;
                }
            }
        }
        cout << res << endl;
    }
}