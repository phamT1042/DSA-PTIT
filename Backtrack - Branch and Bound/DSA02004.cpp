#include<bits/stdc++.h>
using namespace std;
int n, k, a[8][8], visited[8][8];
char kiTu[4] = {'D', 'R', 'L', 'U'};
int dx[4] = {1, 0, 0, -1};    //D,R,L,U
int dy[4] = {0, 1, -1, 0};
string tmp;
vector<string> res;
void Try (int i, int j) {
    if (i == n - 1 && j == n - 1) {
        res.push_back(tmp);
        return;
    }
    for (int l = 0; l < 4; l++) {
        int i1 = i + dx[l];
        int j1 = j + dy[l];
        if (i1 < n && i1 >= 0 && j1 < n && j1 >= 0 && a[i1][j1] && !visited[i1][j1]) {
            visited[i1][j1] = 1;
            tmp += kiTu[l];
            Try (i1, j1);
            visited[i1][j1] = 0;
            tmp.pop_back();
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                cin >> a[i][j];
        if (a[0][0] && a[n - 1][n - 1]) {
            tmp = "";
            visited[0][0] = 1;
            Try(0, 0);
            if (res.empty()) cout << -1;
            else {
                sort(res.begin(), res.end());
                for (string x : res) cout << x << ' ';
                res.clear();
            }
        }
        else cout << -1;
        cout << "\n";
    }
    return 0;
}