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
void deleteFirst (Node *&first) {
    if (first == NULL) return;
    first = first->next;
}
void deleteX (Node *&first, int x) {
    int check = search (first, x);
    while (check != -1) {
        if (check == 1) deleteFirst(first);
        else {
            Node *beforeX = first;
            for (int i = 1; i <= check - 2; i++) {
                beforeX = beforeX->next;
            }
            Node *X = beforeX->next;
            beforeX->next = X->next;
            delete X;
        }
        check = search (first, x);
    }
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
        insertLast(first, a);
    }
    cin >> x;
    deleteX(first, x);
    in(first);
    return 0;
}