#include<bits/stdc++.h>
using namespace std;
int used[6], shNumber[6], shDau[5];
vector<string> hvNumber, hvDau;
void saveDau() {
    string s = " ";
    for (int i = 1; i <= 4; i++) {
        s += to_string(shDau[i]);
    }
    hvDau.push_back(s);
}
void TryDau(int i) {
    for (int j = 1; j <= 3; j++) {
        shDau[i] = j;
        if (i == 4) saveDau();
        else TryDau(i + 1);
    }
}
void saveNumber() {
    string s = " ";
    for (int i = 1; i <= 5; i++) {
        s += to_string(shNumber[i]);
    }
    hvNumber.push_back(s);
}
void TryNumber(int i) {
    for (int j = 1; j <= 5; j++) {
        if (!used[j]) {
            shNumber[i] = j;
            used[j] = true;
            if (i == 5) saveNumber();
            else TryNumber(i + 1);
            used[j] = false;
        }
    }
}
void xayDung() {
    TryNumber(1);
    TryDau(1);
}
bool check(int a[]) {
    for (string x : hvDau) {
        int ans;
        for (string y : hvNumber) {
            ans = a[y[1] - '0'];
            for (int i = 1; i <= 4; i++) {
                switch (x[i]) {
                    case '1': ans += a[y[i + 1] - '0']; break;
                    case '2': ans -= a[y[i + 1] - '0']; break;
                    case '3': ans *= a[y[i + 1] - '0']; break;
                }
            }
            if (ans == 23) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    xayDung();
    int t; cin >> t;
    while (t--) {
        int a[6], flag = 0;
        for (int i = 1; i <= 5; i++) cin >> a[i];
        if (check(a))  cout << "YES\n";
        else cout << "NO\n";
    } 
}