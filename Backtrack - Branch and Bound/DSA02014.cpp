#include<bits/stdc++.h>
using namespace std;
vector<string> dic, res;
int k, m, n;
char a[3][3];
bool visited[3][3];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void TryDFS (int i, int j, string s) {
    for (string x : dic) if (x == s) res.push_back(s);
    for (int o = 0; o < 8; o++) {
        int i1 = i + dx[o];
        int j1 = j + dy[o];
        if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && !visited[i1][j1]) {
            visited[i1][j1] = true;
            TryDFS(i1, j1, s + a[i1][j1]);
            visited[i1][j1] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> k >> m >> n;
        string s;
        while (k--) {
            cin >> s;
            dic.push_back(s);
        }
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                memset(visited, false, sizeof(visited));
                visited[i][j] = true;
                s = "";
                TryDFS(i, j, s + a[i][j]);
            }
        }
        if (res.size()) {
            for (string x : res) cout << x << ' ';
            res.clear();
        }
        else cout << "-1";
        cout << endl;
        dic.clear();
    }
}