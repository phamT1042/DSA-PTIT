 #include<bits/stdc++.h>
using namespace std;
vector<string> lp;
string check (string s) {
    for (int i = 0; i <= 100; i++) {
        if (lp[i].length() > s.length()) continue;
        int j = 0, k = 0;
        while (j < lp[i].length() && k < s.length()) {
            if (lp[i][j] == s[k]) {
                j++; k++;
            }
            else k++;
        }
        if (j == lp[i].length()) return lp[i];
    }
    return "-1";
}
int main() {
    int t; cin >> t;
    for (int i = 100; i >= 0; i--) {
        lp.push_back(to_string(i * i * i));
    }
    while (t--) {
        string s; cin >> s;
        cout << check(s) << endl;
    }
}