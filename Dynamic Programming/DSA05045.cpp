#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<int, int> x, pair<int, int> y) {
    return (double) x.first / x.second > (double) y.first / y.second;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, w; cin >> n >> w;
        vector<pair<int, int>> item(n);
        for (int i = 0; i < n; i++) {
            cin >> item[i].first >> item[i].second;
        }
        sort(item.begin(), item.end(), cmp);
        double res = 0;
        int i = 0;
        while (w - item[i].second > 0 && i < n) {
            res += item[i].first;
            w -= item[i].second;
            i++;
        }
        if (w > 0 && i < n) res += item[i].first * ((double) w / item[i].second);
        cout << fixed << setprecision(2) << res << "\n";
    }
    return 0;
}

