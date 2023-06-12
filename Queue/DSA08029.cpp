#include<bits/stdc++.h>
using namespace std;
string xoayTrai (string s) {
    string tmp = s;
    swap(tmp[0], tmp[3]);
    swap(tmp[3], tmp[4]);
    swap(tmp[4], tmp[1]);
    return tmp;
}
string xoayPhai (string s) {
    string tmp = s;
    swap(tmp[1], tmp[4]);
    swap(tmp[4], tmp[5]);
    swap(tmp[5], tmp[2]);
    return tmp;
}
int solve (string start, string end) {
    queue<pair<string, int>> q;
    q.push({start, 0});
    string tmp;
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        tmp = xoayTrai(it.first);
        if (tmp == end) return it.second + 1;
        else q.push({tmp, it.second + 1});
        tmp = xoayPhai(it.first);
        if (tmp == end) return it.second + 1;
        else q.push({tmp, it.second + 1});
    }
    return 0;
}
int main () {
    int t; cin >> t;
    while (t--) {
        string start, end;
        char add;
        for (int i = 0; i < 6; i++) {
            cin >> add;
            start += add;
        }
        for (int i = 0; i < 6; i++) {
            cin >> add;
            end += add;
        }
        if (start == end) cout << 0;
        cout << solve (start, end);
        cout << "\n";
    }
    return 0;
}
