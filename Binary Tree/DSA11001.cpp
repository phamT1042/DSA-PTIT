#include<bits/stdc++.h>
using namespace std;
struct Node {
    char data;
    Node *left, *right;
};
Node *makeNode (char x) {
    Node *tmp = new Node();
    tmp->data = x;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
int complete;
void addNode (Node *&root, char x) {
    if (root == NULL) {
        Node *tmp = makeNode(x);
        root = tmp;
        complete = 1;
    }
    else if (root->data >= 'a' && root->data <= 'z') return;
    else {
        addNode(root->right, x);
        if (!complete) addNode(root->left, x);
    }
}
void LNR (Node *root) {
    if (root != NULL) {
        LNR (root->left);
        cout << root->data;
        LNR (root->right);
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        Node *root = NULL;
        for (int i = s.length() - 1; i >= 0; i--) {
            complete = 0;
            addNode(root, s[i]);
        }
        LNR (root);
        cout << '\n';
    }
    return 0;
}