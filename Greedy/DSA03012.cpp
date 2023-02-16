#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int dem[26] = {0};
        for (char x : s) dem[x - 'a']++;
        int MAX = *max_element(dem, dem + 26);
        if (MAX <= s.length() - MAX + 1) cout << "1\n";
        else cout << "-1\n";
    }
}