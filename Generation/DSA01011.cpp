#include <bits/stdc++.h>
using namespace std;
int hVtiep(string s) {
    int n = s.length();
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1]) i--;
    if (i == -1) return 0;
    int k = n - 1;
    while (s[k] <= s[i]) k--;
    swap(s[i], s[k]);
    int l = i + 1, r = n - 1;
    while (l < r) swap(s[l++], s[r--]);
    cout << s << endl;
    return 1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; string s; cin >> n >> s;
        cout << n << ' ';
        if (!hVtiep(s)) 
            cout << "BIGGEST\n";
    }
    return 0;
}