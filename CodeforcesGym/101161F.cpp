#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* child[26];
    int grundy;

    Node(): grundy(0) { memset(child, 0, sizeof(child)); }
};

const int MAXS = 40;
int test, n;
char s[MAXS+5];
Node *root;

void insert(Node *&node, int pos) {
    if (node == NULL)
        node = new Node();
    if (s[pos] == 0)
        return;

    int c = s[pos] - 'a';
    if (node->child[c]) {
        node->grundy ^= node->child[c]->grundy + 1;
    }
    insert(node->child[c], pos + 1);
    node->grundy ^= node->child[c]->grundy + 1;
}

void clear(Node *&node) {
    if (node == NULL) return;

    for (int i = 0; i < 26; ++i)
        clear(node->child[i]);
    node = NULL;
}

int main() {
    scanf("%d", &test);

    for (int tt = 1; tt <= test; ++tt) {
        printf("Case %d:\n", tt);

        scanf("%d", &n);
        while (n --> 0) {
            scanf("%s", s);
            insert(root, 0);
        }

        scanf("%d", &n);
        while (n --> 0) {
            scanf("%s", s);
            insert(root, 0);
            if (root->grundy) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", 2);
            }
        }

        clear(root);
    }
    return 0;
}
