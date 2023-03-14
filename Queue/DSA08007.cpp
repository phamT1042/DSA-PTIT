#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        queue<string> q;
        q.push("1");
        int cnt = 0;
        while (stoll(q.front()) <= n) {
            cnt++;
            q.push(q.front() + "0");
            q.push(q.front() + "1");
            q.pop();
        }
        cout << cnt << endl;
    }
    return 0;
}