#include<bits/stdc++.h>
using namespace std;
int main() {
	int v, e; cin >> v >> e;
	vector<int> ke[v + 1];
	int visited[v + 1];
	while (e--) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	int cnt = 1;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i : ke[u]) {
			if (!visited[i]) {
				cnt++;
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	if (cnt == v) cout << 0;
	else {
		for (int i = 2; i <= v; i++) {
			if (!visited[i]) cout << i << '\n';
		}
	}
	return 0;
}
