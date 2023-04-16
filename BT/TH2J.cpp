#include<bits/stdc++.h>
using namespace std;
int visited[10001];
vector<pair<int, int>> dsCanh;
vector<int> ke[10001];
int dinhTru (int v, int tplt) {
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		int tplt2 = 0;
		for (int j = 1; j <= v; j++) visited[j] = 0;
		visited[i] = 1;
		for (int j = 1; j <= v; j++) {
			if (!visited[j]) {
				tplt2++;
				queue<int> q;
				q.push(j);
				visited[j] = 1;
				while (q.size()) {
					int u = q.front(); q.pop();
					for (int k : ke[u]) {
						if (!visited[k]) {
							visited[k] = 1;
							q.push(k);
						}
					}
				}
			}
		}
		if (tplt2 > tplt) cnt++;
	}
	return cnt;
}
int canhCau (int v, int tplt) {
	int cnt = 0;
	for (auto it : dsCanh) {
		int tplt2 = 0;
		for (int j = 1; j <= v; j++) visited[j] = 0;
		for (int j = 1; j <= v; j++) {
			if (!visited[j]) {
				tplt2++;
				queue<int> q;
				q.push(j);
				visited[j] = 1;
				while (q.size()) {
					int u = q.front(); q.pop();
					for (int k : ke[u]) {
						if (k == it.first && u == it.second || k == it.second && u == it.first) continue;
						if (!visited[k]) {
							visited[k] = 1;
							q.push(k);
						}
					}
				}
			}
		}
		if (tplt2 > tplt) cnt++;
	}
	return cnt;
}
int main() {
	int v, e; cin >> v >> e;
	while (e--) {
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
		dsCanh.push_back({x, y});
	}
	int tplt = 0;
	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			tplt++;
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			while (q.size()) {
				int u = q.front(); q.pop();
				for (int j : ke[u]) {
					if (!visited[j]) {
						visited[j] = 1;
						q.push(j);
					}
				}
			}
		}
	}
	cout << dinhTru(v, tplt) << ' ' << canhCau(v, tplt);
	return 0;
}
