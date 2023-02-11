#include<bits/stdc++.h>
using namespace std;
int chon[101], x, k, a[21], n, sum;
vector<string> res;
void result() {
    string s = "{";
    for (int i = 1; i < k; i++) {
        s += to_string(chon[i]);
        if (i < k - 1) s += ' ';
    }
    s += "}";
    res.push_back(s);
}
void Try () {
    if (sum == x) {
        result();
        return;
    }
    else if (sum > x) return;
    for (int j = 0; j < n; j++) {
        if (a[j] >= chon[k - 1]) {
            sum += a[j];
            chon[k++] = a[j];
            Try();
            k--;
            sum -= a[j];
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        memset(chon, 0, sizeof(chon));
        sum = 0; k = 1; 
        Try();
        if (res.size()) {
            cout << res.size() << ' ';
            for (string x : res) cout << x << ' ';
            res.clear();
        }
        else cout << "-1";
        cout << "\n";
    }
}