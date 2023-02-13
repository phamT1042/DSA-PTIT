#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x1, x2; cin >> n;
        vector<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            cin >> x1 >> x2;
            q.push_back({x1, x2});
        }
        sort(q.begin(), q.end(), cmp);
        int res = 1, finish = q[0].second;
        for (int i = 1; i < n; i++) {
            if (q[i].first >= finish) {
                res++;
                finish = q[i].second;
            }
        }
        cout << res << endl;
    }
}