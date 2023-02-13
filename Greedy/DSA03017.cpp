#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        string s; cin >> s;
        map<char, int> dem;
        for (char x : s) dem[x]++;
        priority_queue<int> q;
        for (auto it : dem) q.push(it.second);
        while (k > 0 && q.top() != 0) {
            q.push(q.top() - 1);
            q.pop();
            k--;
        }
        long long res = 0;
        while (!q.empty()) {
            res += q.top() * q.top();
            q.pop();
        }
        cout << res << "\n";
    }
}