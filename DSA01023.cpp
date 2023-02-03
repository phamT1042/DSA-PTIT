#include<bits/stdc++.h>
using namespace std;
int flag;
int ck[15];
void reset (int k) {
    for (int i = 1; i <= k; i++) ck[i] = i;
}
void sinhTH (int a[], int n, int k) {
    int check = 1;
    for (int i = 1; i <= k; i++) {
        if (a[i] != ck[i]) {
            check = 0;
            break;
        }
    }
    if (check) {
        flag = 1;
        return;
    }
    int i = k;
    while (i >= 1 && ck[i] == n - k + i) i--;
    ck[i]++;
    for (int j = i + 1; j <= k; j++) ck[j] = ck[j - 1] + 1;
}
int main () {
    int t; cin >> t;
    while (t--) {
        flag = 0;
        int n, k, res = 0; cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++) cin >> a[i];
        reset(k);
        while (!flag) {
            res++;
            sinhTH(a, n, k);
        }
        cout << res << endl;
    }
    return 0;
}
