#include<bits/stdc++.h>
using namespace std;
vector<string> res;
int a[11];
string s;
int n;
int used[10];
bool cmp (string x, string y) {
    if (x.length() != y.length()) return x.length() < y.length();
    return x < y;
}
void result() {
    string tmp = "";
    for (int i = 0; i < n; i++) {
        tmp += s[a[i]];
    }
    while (tmp[0] == '0') tmp.erase(0, 1);
    res.push_back(tmp);
}
void Try (int i) {
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = 1;
            if (i == n - 1) result();
            else Try(i + 1);
            used[j] = 0;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> s;
        n = s.length();
        memset(used, 0, sizeof(used));
        Try(0);
        sort(res.begin(), res.end(), cmp);
        for (string x : res) cout << x << endl;
        res.clear();
    }
}
