#include<bits/stdc++.h>
using namespace std;
char a[9], c; int n;
bool used[9];
bool check() {
    if (n < 5) {
        if (a[1] == 'A' || a[n] == 'A') return true;
        return false;
    }
    else {
        int checkE, checkA;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 'A') checkA = i;
            if (a[i] == 'E') checkE = i;
        }
        int check = abs(checkA - checkE);
        if (check == 1 || check == n - 1) return true;
        return false;
    }
}
void result() {
    if (check()) {
        for (int i = 1; i <= n; i++) cout << a[i];
        cout << '\n';
    }
}
void Try (int i) {
    for (int j = 'A'; j <= c; j++) {
        if (!used[j - 'A']) {
            a[i] = j;
            used[j - 'A'] = true;
            if (i == n) result();
            else Try(i + 1);
            used[j - 'A'] = false;
        }
    }
}
int main() {
    cin >> c;
    n = c - 'A' + 1;
    Try(1);
}