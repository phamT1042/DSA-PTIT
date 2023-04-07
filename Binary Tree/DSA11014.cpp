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
map<int, Node*> mp;
void kTao (Node *&root) {
    int u, v; char x; 
    cin >> u >> v >> x;
    root = newNode(u);
    mp[u] = root;
    Node *tmp = newNode(v);
    if (x == 'L') {
        mp[u]->left = tmp;
        mp[v] = mp[u]->left;
    }
    else {
        mp[u]->right = tmp;
        mp[v] = mp[u]->right;
    }
}
void addNode (Node *&root, int n) {
    int u, v; char x;
    while (n--) {
        cin >> u >> v >> x;
        Node *tmp = newNode(v);
        if (x == 'L') {
            if (mp[u]->left == NULL) 
                mp[u]->left = tmp;
            else mp[u]->left->data = v;
            mp[v] = mp[u]->left;
        }
        else {
            if (mp[u]->right == NULL)
                mp[u]->right = tmp;
            else mp[u]->right->data = v;
            mp[v] = mp[u]->right;
        }
    }
}
int Sum_All_Right_Leaf_Node (Node *root) {
    int sum = 0;
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
        Node *tmp = q.front(); q.pop();
        if (tmp->right != NULL) {
            if (tmp->right->right == NULL && tmp->right->left == NULL) sum += tmp->right->data;
            else q.push(tmp->right);
        }
        if (tmp->left != NULL) {
            if (tmp->left->right != NULL || tmp->left->left != NULL) q.push(tmp->left);
        }
    }
    return sum;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        Node *root = NULL;
        mp.clear();
        kTao(root);
        addNode(root, n - 1);
        cout << Sum_All_Right_Leaf_Node(root) << '\n';
    }
    return 0;
}