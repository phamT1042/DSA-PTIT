#include<bits/stdc++.h>
using namespace std;
int main() {
    int MOD = 1e9 + 7;
    int t; cin >> t;
    while (t--) {
        int n, x, res = 0; cin >> n;
        priority_queue<int, vector<int>, greater<int>> q;
        while (n--) {
            cin >> x; q.push(x);
        }
        while (q.size() > 1) {
            int day1 = q.top(); q.pop();
            int day2 = q.top(); q.pop();
            res += (day1 + day2) % MOD;
            res %= MOD;
            q.push((day1 + day2) % MOD);
        }
        cout << res << endl;
    }
}