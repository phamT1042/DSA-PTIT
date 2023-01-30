#include<bits/stdc++.h>
using namespace std;
int a[11], n;
int used[11];
void result() {
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << ' ';
}
void Try (int i) {
    for (int j = n; j >= 1; j--) {
        if (used[j] == 0) {
            a[i] = j;
            used[j] = 1;
            if (i == n) result();
            else 
                Try (i + 1);
            used[j] = 0;
        }
    }
}
int main () {
    int t; cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(used, 0, sizeof(used));
        cin >> n;
        Try(1);
        cout << endl;
    }
    return 0;
}
