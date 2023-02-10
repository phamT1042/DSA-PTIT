#include<bits/stdc++.h>
using namespace std;
int n, a[8][8], cot[8], xuoi[20], nguoc[20], res, sh[8];
void result() {
    int gt = 0;
    for (int i = 0; i < 8; i++) {
        gt += a[i][sh[i]];
    }
    res = max(gt, res);
}
void Try (int i) {
    for (int j = 0; j < 8; j++) {
        if (!cot[j] && !xuoi[i - j + 8] && !nguoc[i + j - 1]) {
            sh[i] = j;
            cot[j] = xuoi[i - j + 8] = nguoc[j + i - 1] = 1;
            if (i == 7) result();
            else Try(i + 1);
            cot[j] = xuoi[i - j + 8] = nguoc[j + i - 1] = 0;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        res = INT_MIN;
        for (int i = 0; i < 8; i++) 
            for (int j = 0; j < 8; j++) cin >> a[i][j];
        memset(xuoi, 0, sizeof(xuoi));
        memset(nguoc, 0, sizeof(nguoc));
        memset(cot, 0, sizeof(cot));
        Try(0);
        cout << res << endl;
    }
}