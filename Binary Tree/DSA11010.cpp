#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node *makeNode (int x) {
    Node *tmp = new Node();
    tmp->data = x;
    tmp->left = tmp->right = NULL;
    return tmp;
}
Node *search (Node *root, int u) {
    Node *tmp = NULL;
    if (root->data == u) return root;
    if (root->left != NULL)
        tmp = search(root->left, u);
    if (tmp == NULL)
        if (root->right != NULL) 
            tmp = search(root->right, u);
    return tmp;
}
string Perfect_Tree (Node *root) {
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    int level = 1;
    while (q.size()) {
        auto it = q.front(); q.pop();
        if (it.first->left == NULL && it.first->right == NULL) {
            if (level == 1) level = it.second;
            //Check các node lá cùng mức
            else if (level != it.second) return "No";
        }
        //Check mỗi node trung gian phải đủ 2 node con
        else if (it.first->left != NULL && it.first->right != NULL) {
            q.push({it.first->left, it.second + 1});
            q.push({it.first->right, it.second + 1});
        }
        else return "No";
    }
    return "Yes";
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int u, v; char x;
        cin >> u >> v >> x;
        Node *root = makeNode(u);
        if (x == 'R') root->right = makeNode(v);
        else root->left = makeNode(v);
        n--;
        while(n--) {
            cin >> u >> v >> x;
            Node *p = search(root, u);
            if (x == 'R') p->right = makeNode(v);
            else p->left = makeNode(v);
        }
        cout << Perfect_Tree(root) << '\n';
    }
    return 0;
}