#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n;
        vector<pair<int, int>> a;
        int l[n];
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            a.push_back({x, y});
            l[i] = 1;
        }
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i].first > a[j].second) {
                    l[i] = max(l[i], l[j] + 1);
                }
            }
        }
        cout << *max_element(l, l + n) << endl;
    }
    return 0;
}