#include<bits/stdc++.h>
using namespace std;
char c; int k;
char a[27];
void result() {
    for (int i = 1; i <= k; i++) cout << a[i];
    cout << '\n';
}
void Try (int i) {
    for (char j = a[i - 1]; j <= c; j++) {
        a[i] = j;
        if (i == k) result();
        else Try(i + 1);
    }
}
int main() {
    cin >> c >> k;
    a[0] = 'A';
    Try(1);
    return 0;
}