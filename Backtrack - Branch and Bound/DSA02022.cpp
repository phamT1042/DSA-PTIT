#include<bits/stdc++.h>
using namespace std;
int s[8];
bool check() {
    if ((s[0] == s[1] && s[1] == 0) || s[4] == 0) return false;
    if (s[2] == 0 && s[3] == 2) 
        return true;
    return false;
}
void result() {
    if (check()) {
        for (int i = 0; i < 8; i++) {
            cout << s[i];
            if (i == 1 || i == 3) cout << "/";
        }
        cout << endl; 
    }
}
void Try (int i) {
    for (int j = 0; j <= 2; j++) {
        if (j == 1) continue;
        s[i] = j;
        if (i == 7) result();
        else Try(i + 1);
    }
}
int main() {
    Try(0);
}