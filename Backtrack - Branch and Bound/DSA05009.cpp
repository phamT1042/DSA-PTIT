#include<bits/stdc++.h>
using namespace std;
int a[101], n, sum, check;
void Try (int i, int sum_con) {
    if (check) return;
    for (int j = i; j < n; j++) {
        if (sum_con + a[j] == sum) {
            check = 1;
            return;
        }
        else if (sum_con + a[j] < sum) Try(j + 1, sum_con + a[j]);
        else return;
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        check = 0;
        sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}
        if (sum % 2 == 1) cout << "NO\n";
        else {
            sum /= 2;
            Try(0, 0);
            if (check) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}