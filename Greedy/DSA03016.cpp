#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int s, d; cin >> s >> d;
        if (s > d * 9) cout << "-1";
        else {
            string res = "";
            while (d) {
                if (s >= 9) {
                    res += "9";
                    s -= 9;
                }
                else if (s > 0) {res += to_string(s); s = 0;}
                else res += "0";
                d--;
            }
            reverse(res.begin(), res.end());
            if (res[0] == '0') {
                res[0] = '1';
                for (int i = 1; i < res.length(); i++) {
                    if (res[i] != '0') {
                        res[i]--;
                        break;
                    }
                }
            }
            cout << res;
        }
        cout << "\n";
    }
}