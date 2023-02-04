#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cin.ignore();
        string s; getline(cin, s);
        set<char> res;
        for (int i = 0; i < s.length(); i++) {
            res.insert(s[i]);
        }
        for (char x : res) cout << x << ' ';
        cout << endl;
    }
}