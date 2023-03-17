#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        long long k; string s;
        cin >> k >> s;
        priority_queue<long long> q;
        map<char, long long> cnt;
        for (int i = 0; i < s.length(); i++) cnt[s[i]]++;
        for (auto it : cnt) q.push(it.second);
        while (k > 0 && q.top() > 0) {
            q.push(q.top() - 1);
            k--;
            q.pop();
        }
        long long f = 0;
        while (!q.empty()) {
            f += q.top() * q.top();
            q.pop();
        }
        cout << f << endl;
    }
}