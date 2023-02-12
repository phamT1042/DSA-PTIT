#include<bits/stdc++.h>
using namespace std;
int n;
long long C[16][16], Cmin = LONG_LONG_MAX, Fopt = LONG_LONG_MAX, F = 0;
int sh[16], used[16];
void Try (int i) {
    if (F + Cmin * (n - i + 1) >= Fopt) return;
    for (int j = 2; j <= n; j++) {
        if (!used[j]) {
            sh[i] = j;
            used[j] = 1;
            F += C[sh[i - 1]][sh[i]];
            if (i == n) {
                Fopt = min(Fopt, F + C[sh[n]][1]);
            }
            else Try (i + 1);
            F -= C[sh[i - 1]][sh[i]];
            used[j] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> C[i][j];
            if (C[i][j] > 0 && C[i][j] < Cmin) Cmin = C[i][j];
        }
    }
    sh[1] = 1;
    Try(2);
    cout << Fopt;
}