#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while (t--) {
        string s; cin >> s;
        stack<string> res;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                string tmp = "";
                tmp += s[i];
                res.push(tmp);
            }
            else {
                string bt1 = res.top(); res.pop();
                string bt2 = res.top(); res.pop();
                res.push(bt1 + bt2 + s[i]);
            }
        }
        cout << res.top() << endl;
	}
	return 0;
}