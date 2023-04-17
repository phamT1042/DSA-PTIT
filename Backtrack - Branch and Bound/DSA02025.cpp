#include<bits/stdc++.h>
using namespace std;
int n, sh[10], res = INT_MAX;
vector<string> a;
int used[10];
int f[10][10];  //f[i][j]: so ki tu lap giua xau a[i] va a[j]
void check() {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) 
        cnt += f[sh[i]][sh[i + 1]];
    res = min(res, cnt);
}
void Try (int i) {
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            used[j] = 1;
            sh[i] = j;
            if (i == n - 1) check();
            else Try(i + 1);
            used[j] = 0;
        }
    }
}
int main() {
    cin >> n;
    string s, x, y;
    int k, l, cnt;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a.push_back(s);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            x = a[i];
            y = a[j];
            k = 0; l = 0; cnt = 0;
            while (k < x.length() && l < y.length()) {
                if (x[k] > y[l]) l++;
                else if (x[k] < y[l]) k++;
                else {
                    cnt++; k++; l++;
                }
            }
            f[i][j] = cnt;
            f[j][i] = cnt;
        }
    }
    Try(0);
    cout << res;
    return 0;
}