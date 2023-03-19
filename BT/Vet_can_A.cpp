#include<bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;
int sh[20], sang[100000];
void sangNT() {
    for (int i = 0; i < 100000; i++) sang[i] = 1;
    sang[0] = sang[1] = 0;
    for (int i = 2; i < 317; i++) {
        if (sang[i]) {
            for (int j = i * i; j < 100000; j += i) sang[j] = 0;
        }
    }
}
void in () {
    cnt++;
    if (sang[cnt]) {
        cout << cnt << ": ";
        for (int i = 1; i <= k; i++) {
            cout << sh[i] << ' ';
        }
        cout << endl;
    }
}
void Try (int i) {
    for (int j = sh[i - 1] + 1; j <= n; j++) {
        sh[i] = j;
        if (i == k) in();
        else Try (i + 1);
    }
}
int main() {
    sangNT();
    cin >> n >> k;
    Try(1);
}