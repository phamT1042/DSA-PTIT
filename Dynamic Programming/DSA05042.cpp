#include<bits/stdc++.h>
using namespace std;
string check (long long a[], int n, long long k) {
    set<long long> kt;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == k || kt.count(sum - k) != 0) {
            return "YES";
        }
        kt.insert(sum);
    }
    return "NO";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; long long k; cin >> n >> k;
        long long a[n]; 
        for (long long &x : a) cin >> x;
        cout << check(a, n, k) << endl;
    }
    return 0;
}

