#include<bits/stdc++.h>
using namespace std;
int n, k, a[8][8], visited[8][8], go[65];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
vector<string> res;
void result() {
    string s = "";
    for (int i = 0; i < k; i++) {
        switch(go[i]) {
            case 0: s += "D"; break;
            case 1: s += "R"; break;
            case 2: s += "L"; break;
            case 3: s += "U"; break;
        }
    }
    res.push_back(s);
}
void Try (int i, int j) {
    if (i == n - 1 && j == n - 1) {
        result();
        return;
    }
    for (int l = 0; l < 4; l++) {
        int i1 = i + dx[l];
        int j1 = j + dy[l];
        if (i1 < n && i1 >= 0 && j1 < n && j1 >= 0 && a[i1][j1] == 1 && visited[i1][j1] == 0) {
            visited[i1][j1] = 1;
            go[k] = l;
            k++;
            Try (i1, j1);
            visited[i1][j1] = 0;
            k--;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                visited[i][j] = 0;
            }
        }
        if (a[0][0] == 1 && a[n - 1][n - 1] == 1) {
            k = 0;
            visited[0][0] = 1;
            Try(0, 0);
            if (res.size() == 0) cout << "-1";
            else {
                sort(res.begin(), res.end());
                for (string x : res) cout << x << ' ';
                res.clear();
            }
        }
        else cout << "-1";
        cout << "\n";
    }
    return 0;
}