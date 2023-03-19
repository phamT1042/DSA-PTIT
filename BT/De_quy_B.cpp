#include<bits/stdc++.h>
using namespace std;
int usedCC[10], n;
int sinhCC[10], sinhSo[10];
string s;
void in() {
    cout << s;
    for (int i = 1; i <= n; i++) cout << sinhSo[i];
    cout << endl;
}
void TryNumber (int i) {
    for (int j = 1; j <= n; j++) {
        sinhSo[i] = j;
        if (i == n) in();
        else TryNumber(i + 1);
    }
}
void result() {
    s = "";
    for (int i = 1; i <= n; i++) {
        s += (char) (sinhCC[i] + 64);
    }
    TryNumber(1);
}
void Try (int i) {
    for (int j = 1; j <= n; j++) {
        if (!usedCC[j]) {
            sinhCC[i] = j;
            usedCC[j] = true;
            if (i == n) result();
            else Try (i + 1);
            usedCC[j] = false;
        }
    }
}
int main() {
    cin >> n;
    Try(1);
}
