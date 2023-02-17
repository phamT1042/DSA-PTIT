#include<bits/stdc++.h>
using namespace std;
long long fibo[93];
char Try(int n, long long i) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (i > fibo[n - 2]) return Try (n - 1, i - fibo[n - 2]);
    return Try (n - 2, i);
}
int main() {
    fibo[1] = 1;
    fibo[2] = 1;
    for (int j = 3; j <= 92; j++) fibo[j] = fibo[j - 1] + fibo[j - 2];
    int t; cin >> t;
    while (t--) {
        int n; long long i;
        cin >> n >> i;
        cout << Try(n, i) << endl;
    }
}