#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node (int x) {
        data = x; next = NULL;
    }
};
void insertLast (Node *&first, int x) {
    Node *newNode = new Node(x);
    if (first == NULL) first = newNode;
    else {
        Node *p = first;
        while (p->next != NULL) 
            p = p->next;
        p->next = newNode;
    }
}
int search (Node *first, int x) {
    int cnt = 0;
    for (Node *tmp = first; tmp != NULL; tmp = tmp->next) {
        cnt++;
        if (tmp->data == x) return cnt;
    }
    return -1;
}
void in (Node *first) {
    while (first != NULL) {
        cout << first->data << ' ';
        first = first->next;
    }
}
int main() {
    Node *first = NULL;
    int n, x; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (search(first, a) == -1)
            insertLast(first, a);
    }
    in (first);
    return 0;
}