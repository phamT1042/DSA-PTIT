#include<bits/stdc++.h>
using namespace std;
string s; int n, a[16];
vector<string> res;
void result() {
    string x = "";
    for (int i = 0; i < n; i++) {
        if (a[i]) x += s[i];
    }
    res.push_back(x);
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n - 1) result();
        else Try(i + 1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> s;
        Try(0);
        sort(res.begin(), res.end());
        for (string x : res) cout << x << ' ';
        res.clear();
        cout << endl;
    }
}