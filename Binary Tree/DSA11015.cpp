#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        this->data = x;
        this->left = this->right = NULL;
    }
};
void addNode(Node *&root, int u, int v, char c) {
	if (root == NULL) {
		root = new Node(u);
		Node *tmp = new Node(v);
		if (c == 'L') root->left = tmp;
		else root->right = tmp;
	}
	else {
		if (root->data == u) {
			Node *tmp = new Node(v);
            if (c == 'L') root->left = tmp;
            else root->right = tmp;
		}
		else {
			if (root->left) addNode(root->left, u, v, c);
			if (root->right) addNode(root->right, u, v, c);
		}
	}
}
int res;
int findMax (Node *root) {
    if(root == NULL) return 0;
    int sumLeft = findMax(root->left), sumRight = findMax(root->right);
    if (root->left == NULL && root->right == NULL) 
        return root->data;
    if (root->left == NULL) 
        return sumRight + root->data;
    if (root->right == NULL) 
        return sumLeft + root->data;
    res = max(res, sumLeft + sumRight + root->data);
    return max(sumLeft, sumRight) + root->data;
}
int main() {
    int t; cin >> t;
    while (t--) {
        Node *root = NULL;
        int n; cin >> n;
        while (n--) {
            int u, v; char c; 
            cin >> u >> v >> c;
            addNode(root, u, v, c);
        }
        res = INT_MIN;
        int save = findMax(root);
        cout << res << '\n';
    }
    return 0;
}