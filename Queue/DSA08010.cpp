#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    queue<pair<int, int>> q; 
    q.push({n, 0});
    unordered_map<int, int> check;
    check[n] = 1; 
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i - 1 > 0 && !check[i - 1]) {
            if (i - 1 == 1) return j + 1;
            else {
                q.push({i - 1, j + 1});
                check[i - 1] = 1;
            }
        }
        for (int k = 2; k <= sqrt(i); k++) {
            if (i % k == 0) {
                if (i / k == 1) return j + 1;
                if (!check[i / k]) {
                    q.push({i / k, j + 1});
                    check[i / k] = 1;
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
