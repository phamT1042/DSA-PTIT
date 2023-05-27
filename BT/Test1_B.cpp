#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n, k, x, add; cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    while (n--) {
        cin >> x;
        q.push(x);
    }
    long long cp = 0;
    long long flag = 1;
    while (q.size() > 1) {
        set<long long> save;
        add = 0;
        for (long long i = 0; i < k; i++) {
            if (q.size()) {
                add += q.top();
                save.insert(q.top()); q.pop();
            }
        }
        cp += *save.rbegin() - *save.begin();
        q.push(add);
    }
    cout << q.top() << '\n' << cp;
	return 0; 
}