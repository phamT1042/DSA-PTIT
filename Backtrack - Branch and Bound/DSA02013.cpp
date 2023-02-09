#include<bits/stdc++.h>
using namespace std;
int sang[200], n, p, s, sh[11], used[200];
set<string> res;
void sangNT() {
    for (int i = 0; i < 200; i++) sang[i] = true;
    sang[0] = sang[1] = false;
    for (int i = 2; i < 14; i++) {
        if (sang[i]) {
            for (int j = i * i; j < 200; j += i)
                sang[j] = false;
        }
    }
}
void result() {
    int sum = 0;
    set<int> check;
    string tmp = "";
    for (int i = 0; i < n; i++) {
        sum += sh[i];
        if (sum > s) return;
        check.insert(sh[i]);
    }
    if (sum < s) return;
    for (int x : check) tmp += to_string(x) + ' ';
    tmp.erase(tmp.length() - 1, 1);
    res.insert(tmp);
}
void Try (int i) {
    for (int j = p + 1; j < s; j++) {
        if (sang[j] && !used[j]) {
            used[j] = true;
            sh[i] = j;
            if (i == n - 1) result();
            else Try(i + 1);
            used[j] = false;
        }
    }
}
int main() {
    sangNT();
    int t; cin >> t;
    while(t--) {
        cin >> n >> p >> s;
        memset(used, false, sizeof(used));
        Try(0);
        cout << res.size() << endl;
        for (string x : res) cout << x << endl;
        res.clear();
    }
    return 0;
}