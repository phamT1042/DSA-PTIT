#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
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
void NLR (Node *root) {
    if (root != NULL) {
        cout << root->data << ' ';
        NLR(root->left);
        NLR(root->right);
    }
}
int main () {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n;
        Node *root = NULL;
        while (n--) {
            cin >> x;
            addNode(root, x);
        }
        NLR(root); cout << '\n';
    }
}