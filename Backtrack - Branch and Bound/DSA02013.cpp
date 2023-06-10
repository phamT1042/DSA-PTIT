#include<bits/stdc++.h>
using namespace std;
int n, p, s, sh[11], used[200];
vector<int> nguyenTo;
vector<vector<int>> res;
void sangNT() {
    int sang[200];
    for (int i = 0; i < 200; i++) sang[i] = 1;
    sang[0] = sang[1] = 0;
    for (int i = 2; i < 14; i++) 
        if (sang[i]) 
            for (int j = i * i; j < 200; j += i)
                sang[j] = 0;
    for (int i = 2; i < 200; i++)
        if (sang[i]) nguyenTo.push_back(i);
}
void result() {
    int sum = 0;
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        sum += sh[i];
        tmp.push_back(sh[i]);
        if (sum > s) return;
    }
    if (sum == s) res.push_back(tmp);
}
void Try (int i, int k) {
    for (int j = k; j < nguyenTo.size(); j++) {
        if (!used[nguyenTo[j]]) {
            used[nguyenTo[j]] = 1;
            sh[i] = nguyenTo[j];
            if (i == n - 1) result();
            else Try(i + 1, j + 1);
            used[nguyenTo[j]] = 0;
        }
    }
}
int main() {
    sangNT();
    int t; cin >> t;
    while(t--) {
        cin >> n >> p >> s;
        int i = 0;
        for (i; i < nguyenTo.size(); i++)
            if (nguyenTo[i] > p) break;
        Try(0, i);
        cout << res.size() << '\n';
        for (auto it : res) {
            for (int x : it) cout << x << ' ';
            cout << '\n';
        }
        res.clear();
    }
    return 0;
}