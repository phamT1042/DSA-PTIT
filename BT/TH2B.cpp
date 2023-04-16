#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	cin.ignore();
	while (t--) {
		string s; getline(cin, s);
		string tmp = "";
		for (char x : s) if (x != ' ') tmp += x;
		stack<int> pos;
		for (int i = 0; i < tmp.length(); i++) {
			if (tmp[i] == '(') pos.push(i);
			else if (tmp[i] == ')') {
				if (pos.top() == 0) {
					tmp[0] = ' ';
					tmp[i] = ' ';
				}
				else {
					int dau = 0;
					for (int j = pos.top(); j <= i; j++) {
						if (tmp[j] == '+' || tmp[j] == '-') dau++;
					}
					if (!dau || tmp[pos.top() - 1] == '+' || tmp[pos.top() - 1] == '(') {
						tmp[pos.top()] = ' ';
						tmp[i] = ' ';
					} 
				}
				pos.pop();
			}
		}
		for (char x : tmp) if (x != ' ') cout << x;
		cout << '\n';
	}
	return 0;
}