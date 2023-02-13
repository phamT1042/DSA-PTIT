#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n);
    //4 TH, gộp chung điều kiện mảng kể cả có số 0: (2 số âm cuối, 2 số dương cuối, 3 số dương cuối, 2 số âm cuối + số dương cuối)
    cout << max(a[0] * a[1], max(a[n - 1] * a[n - 2], max(a[n - 1] * a[n - 2] * a[n - 3], a[0] * a[1] * a[n - 1])));
}