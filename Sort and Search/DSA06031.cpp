#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int a[n];
        for (int &x : a) cin >> x;
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (q.size() && a[i] > a[q.back()]) q.pop_back();
            q.push_back(i);
        }
        cout << a[q.front()] << ' ';
        for (int i = k; i < n; i++) {
            if (q.front() <= i - k) q.pop_front();
            while (q.size() && a[i] > a[q.back()]) q.pop_back();
            q.push_back(i);
            cout << a[q.front()] << ' ';
        }
        cout << '\n';
    }
	return 0;
}