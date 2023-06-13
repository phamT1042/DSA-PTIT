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
Node *search (Node *root, int u) {
    if (root->data == u) return root;
    Node *tmp = NULL;
    if (root->left != NULL)
        tmp = search(root->left, u);
    if (tmp == NULL)
        if (root->right != NULL) 
            tmp = search(root->right, u);
    return tmp;
}
void levelOrder (Node *root) {
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
        Node *root = new Node(u);
        if (x == 'R') root->right = new Node(v);
        else root->left = new Node(v);
        n--;
        while(n--) {
            cin >> u >> v >> x;
            Node *p = search(root, u);
            if (x == 'R') p->right = new Node(v);
            else p->left = new Node(v);
        }
        levelOrder(root);
        cout << '\n';
    }
    return 0;
}