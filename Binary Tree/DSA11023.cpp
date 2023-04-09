#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        data = x;
        left = right = NULL;
    }
};
void addNode (Node *&root, int x) {
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    if (root->data < x) addNode(root->right, x);
    else addNode(root->left, x);
}
int Depth_of_Tree (Node *root) {
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    int depth = 0;
    while (q.size()) {
        auto it = q.front(); q.pop();
        depth = max (depth, it.second);
        if (it.first->left != NULL) q.push({it.first->left, it.second + 1});
        if (it.first->right != NULL) q.push({it.first->right, it.second + 1});
    }
    return depth;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n;
        Node *root = NULL;
        while (n--) {
            cin >> x;
            addNode(root, x);
        }
        cout << Depth_of_Tree(root) << '\n';
    }
    return 0;
}