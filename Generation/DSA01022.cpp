#include<bits/stdc++.h>
using namespace std;
int flag;
int ck[11];
void reset (int n) {
    for (int i = 0; i < n; i++) ck[i] = i + 1;
}
void sinhHV (int a[], int n) {
    int check = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != ck[i]) {
            check = 0;
            break;
        }
    }
    if (check) {
        flag = 1;
        return;
    }
    int i = n - 2;
    while (i >= 0 && ck[i] >= ck[i + 1]) i--;
    int k = n - 1;
    while (ck[i] >= ck[k]) k--;
    swap(ck[i], ck[k]);
    int l = i + 1, r = n - 1;
    while (l < r) {
        swap(ck[l++], ck[r--]);
    }
}
int main () {
    int t; cin >> t;
    while (t--) {
        flag = 0;
        int n, res = 0; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        reset(n);
        while (!flag) {
            res++;
            sinhHV(a, n);
        }
        cout << res << endl;
    }
    return 0;
}
