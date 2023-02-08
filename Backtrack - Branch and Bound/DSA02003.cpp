#include<bits/stdc++.h>
using namespace std;
int n, sh[20], a[11][11];
vector<string> res;
void result () {
    int x = 0, y = 0;
    for (int i = 0; i < 2 * n - 2; i++) {
        if (!sh[i]) {
            if (x + 1 < n && a[x + 1][y]) x++;
            else return;
        }
        else {
            if (y + 1 < n && a[x][y + 1]) y++;
            else return;
        }
    }
    if (x == n - 1 && y == n - 1) {
        string s = "";
        for (int i = 0; i < 2 * n - 2; i++) {
            if (sh[i]) s += "R";
            else s += "D";
        }
        res.push_back(s);
    }
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        sh[i] = j;
        if (i == 2 * n - 3) result();
        else Try(i + 1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        if (a[0][0] && a[n - 1][n - 1]) {
            Try(0);
            if (!res.size()) cout << "-1\n";
            else {
                for (string s : res) cout << s << ' ';
                cout << "\n";
                res.clear();
            }
        }
        else cout << "-1\n";
    }
}