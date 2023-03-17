#include<bits/stdc++.h>
using namespace std;
int n;
long long C[20][20], Cmin = LONG_LONG_MAX, Fopt, F;
int sh[20], used[20];
void Try (int i) {
    if (F + Cmin * (n - i + 1) >= Fopt) return;
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            sh[i] = j;
            used[j] = 1;
            F += C[sh[i - 1]][sh[i]];
            if (i == n) Fopt = min(Fopt, F);
            else Try (i + 1);
            F -= C[sh[i - 1]][sh[i]];
            used[j] = 0;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> C[i][j];
            if (C[i][j] > 0 && C[i][j] < Cmin) Cmin = C[i][j];
        }
    }
    memset(used, 0, sizeof(used));
    Fopt = LONG_LONG_MAX;
    F = 0;
    Try(1);
    cout << Fopt << endl;
    }
}