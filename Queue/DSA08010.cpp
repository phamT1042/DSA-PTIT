#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    queue<pair<int, int>> q; 
    q.push({n, 0});
    set<int> check;
    check.insert(n);
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i - 1 > 0 && check.find(i - 1) == check.end()) {
            if (i - 1 == 1) return j + 1;
            else {
                q.push({i - 1, j + 1});
                check.insert(i - 1);
            }
        }
        for (int k = 2; k <= sqrt(i); k++) {
            if (i % k == 0) {
                int select = max(k, i / k);
                if (check.find(select) == check.end()) {
                    if (select == 1) return j + 1;
                    else {
                        q.push({select, j + 1});
                        check.insert(select);
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
