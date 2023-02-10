#include<bits/stdc++.h>
using namespace std;
int n;
int solve(int n) {
    queue<pair<int, int>> q;
    set<int> check;
    q.push({n, 0});
    while (!q.empty()) {
        int gt = q.front().first, soBuoc = q.front().second;
        q.pop();
        if ((gt % 3 == 0 && gt / 3 == 1) || (gt % 2 == 0 && gt / 2 == 1) || (gt - 1 == 1)) return soBuoc + 1;
        if (gt % 3 == 0 && check.count(gt / 3) == 0) {
            q.push({gt / 3, soBuoc + 1});
            check.insert(gt / 3);
        }
        if (gt % 2 == 0 && check.count(gt / 2) == 0) {
            q.push({gt / 2, soBuoc + 1});
            check.insert(gt / 2);
        }
        if (check.count(gt - 1) == 0) {
            q.push({gt - 1, soBuoc + 1});
            check.insert(gt - 1);
        }
    }
    return -1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}