#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        s = " " + s;
        stack<int> number;
        number.push(1);
        int used[10], last, pos, check;
        for (int i = 2; i < 10; i++) used[i] = 0;
        used[1] = 1;
        while (number.size() < s.length()) {
            check = 0;
            if (s[number.size()] == 'I') {
                for (int i = number.top() + 1; i <= 9; i++) {
                    if (!used[i]) {
                        number.push(i);
                        check = 1;
                        used[i] = 1;
                        break;
                    }
                }
            }
            else {
                for (int i = number.top() - 1; i >= 1; i--) {
                    if (!used[i]) {
                        number.push(i);
                        check = 1;
                        used[i] = 1;
                        break;
                    }
                }
            }
            if (!check) {
                pos = number.size();
                last = number.top();
                used[last] = 0;
                number.pop();
                while (number.size() > 0) {
                    if (s[number.size()] != s[pos]) break;
                    last = number.top();
                    used[last] = 0;
                    number.pop();
                } 
                number.push(last + 1);
                used[last + 1] = 1;
            }
        }
        vector<int> res;
        while (number.size()) {
            res.push_back(number.top()); number.pop();
        }
        for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
        cout << '\n';
    }
    return 0;
}