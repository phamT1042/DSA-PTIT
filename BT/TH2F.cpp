#include<bits/stdc++.h>
using namespace std;
char kt[3] = {'A', 'B', 'C'};
struct day {
	string data;
	int cntA, cntB, cntC;
	day (string x, int a, int b, int c) {
		data = x;
		cntA = a;
		cntB = b;
		cntC = c;
	}
};
int check (day s, int n) {
	for (int i = 0; i < 2; i++) {
		if (s.data.find(kt[i]) == string::npos) return 0;
	}
	if (s.cntA <= s.cntB && s.cntB <= s.cntC) return 1;
	return 0;
}
int main() {
	int n; cin >> n;
	queue<day> q;
	q.push(day("A", 1, 0, 0));
	q.push(day("B", 0, 1, 0));
	q.push(day("C", 0, 0, 1));
	while (q.size()) {
		day tmp = q.front(); q.pop();
		if (check(tmp, n)) cout << tmp.data << '\n';
		if (tmp.data.length() < n) {
			for (int i = 0; i < 3; i++) {
				if (i == 0) q.push(day(tmp.data + "A", tmp.cntA + 1, tmp.cntB, tmp.cntC));
				else if (i == 1) q.push(day(tmp.data + "B", tmp.cntA, tmp.cntB + 1, tmp.cntC));
				else q.push(day(tmp.data + "C", tmp.cntA, tmp.cntB, tmp.cntC + 1));
			}
		}
	}
	return 0;
}
