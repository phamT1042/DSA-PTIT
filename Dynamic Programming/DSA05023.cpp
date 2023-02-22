#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        long long res = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                res += stoll(s.substr(i, j - i + 1));
            }
        }
        cout << res << endl;
    }
}