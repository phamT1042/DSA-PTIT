#include<bits/stdc++.h>
using namespace std;
int chon[40], S, t[40], n, sum, res;
void Try (int k) {
    if (sum == S) {
        res = min(res, k - 1);
        return;
    }
    else if (sum > S) return;
    for (int j = chon[k - 1] + 1; j <= n; j++) {
        sum += t[j];
        chon[k] = j;
        Try(k + 1);
        sum -= t[j];
    }
}
int main() {
    int T; cin >> T;
    while (T--) {
        cin >> n >> S;        
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
            chon[i] = 0;
        }
        sort(t + 1, t + n + 1, greater<int>());
        int k = 1;
        sum = 0; res = 40; 
        Try(k);
        if (res != 40) cout << res;
        else cout << "-1";
        cout << "\n";
    }
}