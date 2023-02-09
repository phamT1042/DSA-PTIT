#include<bits/stdc++.h>
using namespace std;
int a[15];
int n, k;
void result() {
    for (int i = 1; i <= k; i++) {
        cout << (char) (a[i] + 65);
    }
    cout << endl;
}
void Try (int i) {
    for (int j = a[i - 1]; j <= n; j++) {
        a[i] = j;
        if (i == k) result();
        else Try(i + 1);
    }
}
int main() {
    char c;
    cin >> c >> k;
    n = c - 'A';
    memset(a, 0, sizeof(a));
    Try(1);
}