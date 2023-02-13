#include<bits/stdc++.h>
using namespace std;
int sumMin (string s1, string s2) {
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '6') s1[i] = '5';
    }
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '6') s2[i] = '5';
    }
    return stoi(s1) + stoi(s2);
}
int sumMax (string s1, string s2) {
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '5') s1[i] = '6';
    }
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '5') s2[i] = '6';
    }
    return stoi(s1) + stoi(s2);
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << sumMin(s1, s2) << ' ' << sumMax(s1, s2);
    return 0;
}