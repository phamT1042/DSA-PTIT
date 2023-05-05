#include<bits/stdc++.h>
using namespace std;
int n, inOrder[1001], preOrder[1001];
struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        this->data = x;
        this->left = this->right = NULL;
    }
};
int i;
void insertNode (Node *&root, int l, int r) {
    if (l <= r && i < n) {
        int j;
        for (j = l; j <= r; j++) {
            if (inOrder[j] == preOrder[i]) break;
        }
        root = new Node(preOrder[i++]);
        insertNode(root->left, l, j - 1);
        insertNode(root->right, j + 1, r);
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
        for (int i = 0; i < n; i++) cin >> preOrder[i];
        Node *root = NULL;
        i = 0;
        insertNode (root, 0, n - 1);
        LRN(root); cout << '\n';
    }
    return 0;
}