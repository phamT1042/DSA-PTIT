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
        int minPos = a[0].second;
        for (int i = 1; i < n; i++) {
            if (a[i].second < minPos) {
                minPos = a[i].second;
            }
            else {
                res = max(res, a[i].second - minPos);
            }
        }
        if (res == INT_MIN) cout << "-1\n";
        else cout << res << endl;
    }
	return 0;
}