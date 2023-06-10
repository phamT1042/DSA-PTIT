#include<bits/stdc++.h>
using namespace std;
int a[11][11], sh[11], n, k;
bool used[11];
vector<vector<int>> res;
int cnt = 0;
void result() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i][sh[i]];
        if (sum > k) return;
    }
    if (sum == k) {
        cnt++;
        vector<int> child;
        for (int i = 1; i <= n; i++) 
            child.push_back(sh[i]);
        res.push_back(child);
    }
}
void Try (int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            sh[i] = j;
            used[j] = true;
            if (i == n) result();
            else Try (i + 1);
            used[j] = false;
        }
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    Try(1);
    cout << cnt << endl;
    for (vector<int> a : res) {
        for (int x : a) 
            cout << x << ' ';
        cout << '\n';
    }
}