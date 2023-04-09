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
void Leaf_Node (Node *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL)
            cout << root->data << ' ';
        Leaf_Node(root->left);
        Leaf_Node(root->right);
    }
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
        Leaf_Node(root); cout << '\n';
    }
    return 0;
}