#include<bits/stdc++.h>
using namespace std;
int cnt, n, m;
void Try(int i, int j) {
    if(i == n - 1 && j == m - 1) cnt++;
    if (i < n - 1) Try(i + 1, j);
    if (j < m - 1) Try(i, j + 1);
}
int main() {
    int t; cin >> t;
    while(t--) {
        int x;
        cin >> n >> m;
        for (int i = 0; i < n * m; i++) cin >> x;
        cnt = 0;
        Try(0, 0);
        cout << cnt << endl;
    }
    return 0;
}