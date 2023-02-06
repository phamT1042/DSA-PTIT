#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back({x, i});
        }
        sort(a.begin(), a.end(), cmp);
        int res = INT_MIN;
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (q.empty()) q.push(a[i].second);
            else {
                int front = q.front();
                if (a[i].second < front) {
                    q.pop();
                    q.push(a[i].second);
                }
                else {
                    res = max(res, a[i].second - front);
                }
            }
        }
        if (res == INT_MIN) cout << "-1\n";
        else cout << res << endl;
    }
	return 0;
}