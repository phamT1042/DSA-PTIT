#include<bits/stdc++.h>
using namespace std;
int n, w, Fopt = 0;
int Xopt[101], sh[101], c[101], a[101];
void result() {
    int gTri = 0, kLg = 0;
    for (int i = 0; i < n; i++) {
        kLg += sh[i] * a[i];
        if (kLg <= w) gTri += sh[i] * c[i];
        else return;
    }
    if (gTri > Fopt) {
        Fopt = gTri;
        for (int i = 0; i < n; i++) {
            Xopt[i] = sh[i];
        }
    }
}
void Try (int i) {
    for (int j = 0; j <= 1; j++) {
        sh[i] = j;
        if (i == n - 1) result();
        else Try(i + 1);
    }
}
int main () {
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    Try(0);
    cout << Fopt << endl;
    for (int i = 0; i < n; i++) cout << Xopt[i] << ' ';
    return 0;
}
