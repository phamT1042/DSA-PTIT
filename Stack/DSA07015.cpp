#include<bits/stdc++.h>
using namespace std;
int mucDoUuTien (string x) {
    if (x == "+" || x == "-") return 1;
    if (x == "*" || x == "/") return 2;
    return 0;
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<string> bt;
        bt.push_back("(");
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                string number = "";
                while (s[i] >= '0' && s[i] <= '9') number += s[i++];
                i--;
                bt.push_back(number);
            }
            else bt.push_back(string(1, s[i]));
        }
        bt.push_back(")");
        //Chuyển biểu thức trung tố sang hậu tố 
        stack<string> change;
        vector<string> hauTo;
        string tmp;
        for (string x : bt) {
            if (x == "(") change.push(x);
            else if (x == ")") {
                while (change.size()) {
                    tmp = change.top();
                    change.pop();
                    if (tmp == "(") break;
                    hauTo.push_back(tmp);
                }
            }
            else {
                int uuTien = mucDoUuTien(x);
                if (!uuTien) hauTo.push_back(x);
                else {
                    while (change.size()) {
                        tmp = change.top();
                        if (mucDoUuTien(tmp) < uuTien) break;
                        hauTo.push_back(tmp);
                        change.pop();
                    }
                    change.push(x);
                }
            }
        }
        while (change.size()) {
            hauTo.push_back(change.top());
            change.pop();
        }
        //Tính biểu thức hậu tố
        stack<long long> tinhHauTo;
        for (string x : hauTo) {
            if (x[0] >= '0' && x[0] <= '9') 
                tinhHauTo.push(stoll(x));
            else {
                long long a = tinhHauTo.top(); tinhHauTo.pop();
                long long b = tinhHauTo.top(); tinhHauTo.pop();
                if (x == "+") tinhHauTo.push(a + b);
                else if (x == "-") tinhHauTo.push(b - a);
                else if (x == "*") tinhHauTo.push(a * b);
                else tinhHauTo.push(b / a);
            }
        }
        cout << tinhHauTo.top() << '\n';
    }
    return 0;
}
