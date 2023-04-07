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
int check_Leaf_Node (Node *root) {
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int level = 1;
    while (q.size()) {
        auto it = q.front(); q.pop();
        if (it.first->left == NULL && it.first->right == NULL) {
            if (level == 1) level = it.second;
            else if (level != it.second) return 0;
        }
        if (it.first->left != NULL) q.push({it.first->left, it.second + 1});
        if (it.first->right != NULL) q.push({it.first->right, it.second + 1});
    }
    return 1;
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
        cout << check_Leaf_Node(root) << '\n';
    }
    return 0;
}