#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<char, int> x, pair<char, int> y) {
    return x.second > y.second;
} 
int check (string s, int d) {
    map<char, int> dem;
    vector<pair<char, int>> kiTu;
    for (int i = 0; i < s.length(); i++) {
        dem[s[i]]++;
        s[i] = ' ';
    }
    for (auto it : dem) kiTu.push_back({it.first, it.second});
    sort(kiTu.begin(), kiTu.end(), cmp);
    for (int i = 0; i < kiTu.size(); i++) {
        int j = 0;
        while (s[j] != ' ') j++;
        for (int k = 0; k < kiTu[i].second; k++) {
            if (j + d * k >= s.length()) return -1;
            s[j + d * k] = kiTu[i].first;
        }
    }
    return 1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int d; cin >> d;
        string s; cin >> s;
        cout << check(s, d) << endl;
    }
}