#include<bits/stdc++.h>
using namespace std;
int flag = 0;
int sh[11];
void sinhHV(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[sh[i] - 1] << ' ';
    }
    cout << endl;
    int i = n - 1;
    while (i >= 0 && sh[i] > sh[i + 1]) i--;
    if (i == -1) {
        flag = 1;
        return;
    }
    int k = n - 1;
    while (sh[k] < sh[i]) k--;
    swap(sh[k], sh[i]);
    int l = i + 1, r = n - 1;
    while (l < r) {
        swap(sh[l++], sh[r--]);
    }
}
int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sh[i] = i + 1;
    }
    sort(a, a + n);
    while (!flag) {
        sinhHV(a, n);
    }
    return 0;
}