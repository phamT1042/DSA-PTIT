#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    cin.ignore();
    while (t--) {
        int n; cin >> n;
        int a[n], res[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            res[i] = 1;
        }
        stack<int> q;
        q.push(0);
        for (int i = 1; i < n; i++) {
            while (a[i] >= a[q.top()]) {
                res[i] += res[q.top()];
                q.pop();
                if (q.empty()) break;
            }
            q.push(i);
        }
        for (int x : res) cout << x << ' ';
        cout << endl;
    }
}