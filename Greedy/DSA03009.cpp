#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<int, int> x, pair<int, int> y) {
    return x.second > y.second;
}
int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int>> cv;
		int chon[1001] = {0};
		for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            cv.push_back({y, z});
        }
		sort(cv.begin(), cv.end(), cmp); 
		int res = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = cv[i].first; j > 0; j--) { 
				if (chon[j] == 0) {
					chon[j] = 1;
                    res += cv[i].second;
                    cnt++;
                    break;
				}
			}
		}
		cout << cnt << ' ' << res << endl;
	}
}