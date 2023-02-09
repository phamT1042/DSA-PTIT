#include<bits/stdc++.h>
using namespace std;
int a[10], n;
bool used[10];
bool check() {
    if (n < 5) {
        int i;
        for (i = 1; i <= n; i++) if (a[i] == 1) break;
        if (i == 1 || i == n) return true;
        else return false;
    }
    else {
        int checkE, checkA;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) checkA = i;
            if (a[i] == 5) checkE = i;
        }
        if ((checkA == 1 && checkE == n) || (checkA == n && checkE == 1) || (checkE == checkA + 1) || (checkE == checkA - 1)) return true;
        else return false;
    }
}
void result() {
    if (check()) {
        for (int i = 1; i <= n; i++) cout << (char) (a[i] + 64);
        cout << endl;
    }
}
void Try (int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = true;
            if (i == n) result();
            else Try(i + 1);
            used[j] = false;
        }
    }
}
int main() {
    char c; cin >> c;
    n = c - 'A' + 1;
    Try(1);
}