#include<bits/stdc++.h>
using namespace std;
long long C[1001][1001];
long long MOD = 1e9 + 7;
void toHop() {
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == i) C[i][j] = 1;
            else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= MOD;
            }
        }
    }
}
int main() {
    toHop();
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        cout << C[n][k] << endl;
    }
}