#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n], res[n];
        map<int, int> dem;
        for (int &x : a) {
            cin >> x;
            dem[x]++;
        }
        stack<int> greater;
        greater.push(0);
        for (int i = 1; i < n; i++) {
            while (dem[a[i]] > dem[a[greater.top()]]) {
                res[greater.top()] = a[i];
                greater.pop();
                if (greater.empty()) break;
            }
            greater.push(i);
        }
        while (!greater.empty()) {
            res[greater.top()] = -1;
            greater.pop();
        }
        for (int x : res) cout << x << ' ';
        cout << endl;
    }
}