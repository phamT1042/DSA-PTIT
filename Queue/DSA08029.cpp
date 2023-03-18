#include<bits/stdc++.h>
using namespace std;
class Matrix {
    private:
        int a[2][3];
    public:
        friend istream &operator >> (istream &in, Matrix &x) {
            for (int i = 0; i < 2; i++) 
                for (int j = 0; j < 3; j++)
                    in >> x.a[i][j];
            return in;
        }
        friend ostream &operator << (ostream &out, Matrix x) {
            for (int i = 0; i < 2; i++) 
                for (int j = 0; j < 3; j++)
                    out << x.a[i][j] << ' ';
                out << endl;
            return out;
        }
        friend bool operator == (Matrix x, Matrix y) {
            for (int i = 0; i < 2; i++) 
                for (int j = 0; j < 3; j++)
                    if (x.a[i][j] != y.a[i][j]) return false;
            return true;
        }
        void xoayTrai () {
            swap(this->a[0][0], this->a[0][1]);
            swap(this->a[0][0], this->a[1][0]);
            swap(this->a[1][0], this->a[1][1]);
        }
        void xoayPhai () {
            swap(this->a[0][1], this->a[0][2]);
            swap(this->a[0][1], this->a[1][1]);
            swap(this->a[1][1], this->a[1][2]);
        }
};
int solve (Matrix start, Matrix end) {
    queue<pair<Matrix, int>> q;
    q.push({start, 0});
    while (!q.empty()) {
        auto it = q.front(); q.pop();
        Matrix tmp = it.first;
        tmp.xoayTrai();
        if (tmp == end) return it.second + 1;
        else q.push({tmp, it.second + 1});
        tmp = it.first;
        tmp.xoayPhai();
        if (tmp == end) return it.second + 1;
        else q.push({tmp, it.second + 1});
    }
    return 0;
}
int main () {
    int t; cin >> t;
    while (t--) {
        Matrix start, end;
        cin >> start >> end;
        if (start == end) cout << 0;
        cout << solve (start, end);
        cout << "\n";
    }
    return 0;
}
