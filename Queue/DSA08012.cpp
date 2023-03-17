#include <bits/stdc++.h>
using namespace std;
vector<int> number;
int used[6], sh[6], n;
void Try (int i) {
    for (int j = 0; j <= 5; j++) {
        if (i == 0 && j == 0) continue;
        if (!used[j]) {
            sh[i] = j;
            used[j] = 1;
            if (i == n - 1) {
                string s = "";
                for (int k = 0; k < n; k++) s += to_string(sh[k]);
                number.push_back(stoi(s));
            }
            else Try (i + 1);
            used[j] = 0;
        }
    }
}
void sinhHV() {
    for (int i = 0; i < 6; i++) number.push_back(i);
    for (n = 2; n <= 5; n++) {
        memset(used, 0, sizeof(used));
        Try(0);
    }
    number.push_back(100000);
}
int main() {
    sinhHV();
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int cnt = 0;
        for (int x : number) {
            if (x >= l && x <= r) cnt++;
            else if (x > r) break;
        }
        cout << cnt << endl;
    }
    return 0;
}
