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
int res;
void Count_Parent_Node (Node *root) {
    if (root != NULL) {
        if (root->left != NULL || root->right != NULL)
            res++;
        Count_Parent_Node(root->left);
        Count_Parent_Node(root->right);
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
        res = 0;
        Count_Parent_Node(root); 
        cout << res << '\n';
    }
    return 0;
}