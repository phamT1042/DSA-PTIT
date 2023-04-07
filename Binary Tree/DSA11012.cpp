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
int Two_Binary_Tree_Equal (Node *root1, Node *root2) {
    vector<int> tree1, tree2;
    Node *tmp;
    queue<Node*> q;
    q.push(root1);
    while (q.size()) {
        tmp = q.front(); q.pop();
        tree1.push_back(tmp->data);
        if (tmp->left != NULL) q.push(tmp->left);
        if (tmp->right != NULL) q.push(tmp->right);
    }
    int i = 0;
    q.push(root2);
    while (q.size()) {
        tmp = q.front(); q.pop();
        if (tree1[i++] != tmp->data) return 0;
        if (tmp->left != NULL) q.push(tmp->left);
        if (tmp->right != NULL) q.push(tmp->right);
    }
    return 1;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n1; cin >> n1;
        Node *root1 = NULL;
        kTao(root1);
        addNode(root1, n1 - 1);
        int n2; cin >> n2;
        Node *root2 = NULL;
        kTao(root2);
        addNode(root2, n2 - 1);
        if (n1 != n2) cout << "0";
        else 
            cout << Two_Binary_Tree_Equal(root1, root2);
        cout << '\n';
    }
    return 0;
}