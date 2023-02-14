#include<bits/stdc++.h>
using namespace std;
int main() {
    int s, d; cin >> d >> s;
    if (s > d * 9 || ((s == 0) && (d != 1))) cout << "-1 -1";
    else if (s == 0 && d == 1) cout << "0 0";
    else {
        string maxNum = "";
        while (d) {
            if (s >= 9) {
                maxNum += "9";
                s -= 9;
            }
            else if (s > 0) {maxNum += to_string(s); s = 0;}
            else maxNum += "0";
            d--;
        }
        string minNum = "";
        for (int i = maxNum.length() - 1; i >= 0; i--) minNum += maxNum[i]; 
        if (minNum[0] == '0') {
            minNum[0] = '1';
            for (int i = 1; i < minNum.length(); i++) {
                if (minNum[i] != '0') {
                    minNum[i]--;
                    break;
                }
            }
        }
        cout << minNum << ' ' << maxNum;
    }
}