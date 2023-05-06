#include<bits/stdc++.h>
using namespace std;
string xoayTraiDi (string x) {
    string a = x;
    swap(a[0], a[3]);
    swap(a[3], a[7]);
    swap(a[7], a[8]);
    swap(a[8], a[5]);
    swap(a[5], a[1]);
    return a;
}
string xoayPhaiDi (string x) {
    string a = x;
    swap(a[1], a[4]);
    swap(a[4], a[8]);
    swap(a[8], a[9]);
    swap(a[9], a[6]);
    swap(a[6], a[2]);
    return a;
}
string xoayTraiVe (string x) {
    string a = x;
    swap(a[0], a[1]);
    swap(a[1], a[5]);
    swap(a[5], a[8]);
    swap(a[8], a[7]);
    swap(a[7], a[3]);
    return a;
}
string xoayPhaiVe (string x) {
    string a = x;
    swap(a[1], a[2]);
    swap(a[2], a[6]);
    swap(a[6], a[9]);
    swap(a[9], a[8]);
    swap(a[8], a[4]);
    return a;
}
int solve (string start) {
    queue<pair<string, int>> q1, q2;
    map<string, int> check;
    string tmp, left, right;
    int res = INT_MAX;
    string end = "1238004765";
    q1.push({start, 0});
    q2.push({end, 0});
    while (q1.size()) {
        auto it = q1.front(); q1.pop();
        tmp = it.first;
        left = xoayTraiDi(tmp);
        if (!check[left]) {
            check[left] = it.second + 1;
            q1.push({left, it.second + 1});
        }
        right = xoayPhaiDi(tmp);
        if (!check[right]) {
            check[right] = it.second + 1;
            q1.push({right, it.second + 1});
        }
        if (it.second == 14) break;
    }
    while (q2.size()) {
        auto it = q2.front(); q2.pop();
        tmp = it.first;
        if (check[tmp])
            res = min(res, check[tmp] + it.second);
        left = xoayTraiVe(tmp);
        q2.push({left, it.second + 1});
        right = xoayPhaiVe(tmp);
        q2.push({right, it.second + 1});
        if (it.second == 14) break;
    }
    return res;
}
int main () {
    int t; cin >> t;
    while (t--) {
        string start = "";
        int x; 
        for (int i = 0; i < 10; i++) {
            cin >> x; 
            start += string(1, x + '0');
        }
        cout << solve(start) << '\n';
    }
    return 0;
}