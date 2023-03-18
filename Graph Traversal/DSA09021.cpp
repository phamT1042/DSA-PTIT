#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n;
    vector<int> ke[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x) ke[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int x : ke[i]) cout << x << ' ';
        cout << endl;
    }
    return 0;
}

