#include<bits/stdc++.h>
using namespace std;
int sh[11];
string s; int n;
bool used[11];
void result() {
    for (int i = 0; i < n; i++) {
        cout << s[sh[i]];
    }
    cout << ' ';
}
void Try (int i) {
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = true;
            sh[i] = j;
            if (i == n - 1) result();
            else Try (i + 1);
            used[j] = false;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> s;
        n = s.length();
        memset(used, false, sizeof(used));
        Try(0);
        cout << endl;
    }
}