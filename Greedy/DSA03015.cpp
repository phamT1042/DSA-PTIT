#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        //Chết khi lượng cần (m) > lượng mua (n) trong ngày hoặc
        //lượng mua trong 6 ngày (6n) không đủ cho cả ngày chủ nhật (7m) vì ngày chủ nhật không bán 
        if (m > n || 6 * n < 7 * m) cout << "-1";
        else {
            int res = (s * m) / n;
            int du =  (s * m) % n;
            if (du > 0) cout << res + 1;
            else cout << res;
        }
        cout << endl;
    }
}