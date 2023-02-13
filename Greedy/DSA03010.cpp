#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n;
        long long res = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        while (n--) {
            cin >> x; q.push(x);
        }
        while (q.size() > 1) {
            int day1 = q.top(); q.pop();
            int day2 = q.top(); q.pop();
            res += day1 + day2;
            q.push(day1 + day2);
        }
        cout << res << endl;
    }
}