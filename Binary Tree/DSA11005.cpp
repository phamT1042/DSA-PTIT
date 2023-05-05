#include<bits/stdc++.h>
using namespace std;
int n, inOrder[1001], levelOrder[1001];
struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        this->data = x;
        this->left = this->right = NULL;
    }
};
void insertNode (Node *&root, int i, int l, int r) {
    if (l <= r && i < n) {
        int j, flag = 0;
        for (j = l; j <= r; j++) {
            if (inOrder[j] == levelOrder[i]) {
                flag = 1; break;
            }
        }
        if (flag) {
            root = new Node(levelOrder[i]);
            insertNode(root->left, i + 1, l, j - 1);
            insertNode(root->right, i + 1, j + 1, r);
        }
        else 
            insertNode(root, i + 1, l, r);
    }
}
void LRN (Node *root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data << ' ';
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> inOrder[i];
        for (int i = 0; i < n; i++) cin >> levelOrder[i];
        Node *root = NULL;
        insertNode (root, 0, 0, n - 1);
        LRN(root); cout << '\n';
    }
    return 0;
}