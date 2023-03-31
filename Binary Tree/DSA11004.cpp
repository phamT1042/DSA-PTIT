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
void levelTree (Node *root) {
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
        Node *tmp = q.front(); q.pop();
        cout << tmp->data << ' ';
        if (tmp->left != NULL) q.push(tmp->left);
        if (tmp->right != NULL) q.push(tmp->right);
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
        levelOrder(root);
        cout << '\n';
    }
    return 0;
}