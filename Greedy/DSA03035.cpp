#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}
int main() {
    int n; cin >> n;
    //Sắp xếp lại mảng tăng dần và lưu chỉ số sau thay đổi tương ứng số vào vector q
    //Kiểm tra mảng vị trí xem độ dài dãy vị trí tăng dài nhất là bao nhiêu
    //Tức dãy đó đã được sắp xếp rồi, chỉ cần sắp xếp các vị trí còn lại là được
    int a[n], length[n];
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        length[i] = 1;
        q.push_back({i, a[i]});
    }
    sort(q.begin(), q.end(), cmp);
    for (int i = 1; i < n; i++) {
        if (q[i].first > q[i - 1].first) length[i] = length[i - 1] + 1;
    }
    cout << n - *max_element(length, length + n);
}