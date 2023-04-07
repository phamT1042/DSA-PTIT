#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node *newNode (int x) {
    Node *tmp = new Node();
    tmp->data = x;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
Node *searchNode (Node *root, int x) {
    Node *tmp = NULL;
    if (root->data == x) return root;
    if (root->left != NULL)
        tmp = searchNode(root->left, x);
    if (root->right != NULL && tmp == NULL)
        tmp = searchNode(root->right, x);
    return tmp;
}
void kTao (Node *&root) {
    int u, v; char x; 
    cin >> u >> v >> x;
    root = newNode(u);
    if (x == 'L') root->left = newNode(v);
    else root->right = newNode(v);
}
void addNode (Node *&root, int n) {
    int u, v; char x;
    while (n--) {
        cin >> u >> v >> x;
        Node *tmp = searchNode(root, u);
        if (x == 'L') tmp->left = newNode(v);
        else tmp->right = newNode(v);
    }
}
int Full_Binary_Tree (Node *root) {
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
        Node *tmp = q.front(); q.pop();
        if (tmp->left == NULL && tmp->right == NULL) continue;
        if (tmp->left != NULL && tmp->right != NULL) {
            q.push(tmp->left);
            q.push(tmp->right);
        }
        else return 0;
    }
    return 1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        Node *root = NULL;
        kTao(root);
        addNode(root, n - 1);
        cout << Full_Binary_Tree(root) << '\n';
    }
    return 0;
}