#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node *makeNode (int x) {
    Node *tmp = new Node();
    tmp->data = x;
    tmp->left = tmp->right = NULL;
    return tmp;
}
Node *search (Node *root, int u) {
    Node *tmp = NULL;
    if (root->data == u) return root;
    if (root->left != NULL)
        tmp = search(root->left, u);
    if (tmp == NULL)
        if (root->right != NULL) 
            tmp = search(root->right, u);
    return tmp;
}
void Tree_Spiral_Order (Node *root) {
    queue<pair<Node*, int>> q;
    vector<int> levelOrder[10001];
    q.push({root, 1});
    int levelMax = 1;
    while (q.size()) {
        auto it = q.front(); q.pop();
        levelOrder[it.second].push_back(it.first->data);
        levelMax = max(levelMax, it.second);
        if (it.first->left != NULL) q.push({it.first->left, it.second + 1});
        if (it.first->right != NULL) q.push({it.first->right, it.second + 1});
    }
    for (int i = 1; i <= levelMax; i++) {
        if (i % 2 == 1) {
            for (int j = levelOrder[i].size() - 1; j >= 0; j--)
                cout << levelOrder[i][j] << ' ';
        }
        else {
            for (int x : levelOrder[i])
                cout << x << ' ';
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int u, v; char x;
        cin >> u >> v >> x;
        Node *root = makeNode(u);
        if (x == 'R') root->right = makeNode(v);
        else root->left = makeNode(v);
        n--;
        while(n--) {
            cin >> u >> v >> x;
            Node *p = search(root, u);
            if (x == 'R') p->right = makeNode(v);
            else p->left = makeNode(v);
        }
        Tree_Spiral_Order(root); cout << '\n';
    }
    return 0;
}