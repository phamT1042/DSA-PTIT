while (!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        int i = tmp.first, j = tmp.second;
        if (check.count(i * 2) == 0) {
            if (i * 2 == t) return j + 1;
            else if (i < t) {
                q.push({i * 2, j + 1});
                check.insert(i * 2);
            }
        }
        if (check.count(i - 1) == 0 && i - 1 > 0) {
            if (i - 1 == t) return j + 1;
            else {
                q.push({i - 1, j + 1});
                check.insert(i - 1);
            }
        }
    }
    return 0;