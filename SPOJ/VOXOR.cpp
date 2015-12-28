#include <bits/stdc++.h>

using namespace std;

const int MAXBIT = 30;

struct Node
{
    Node* child[2];
    Node* parent;
    int cnt;
    bool inv;

    Node()
    {
        child[0] = child[1] = NULL;
        parent = NULL;
        cnt = 0;
        inv = 0;
    }
};

int n, q, a[100010], x, xx;
Node* root;
char s[50];

void add(int val, int pos, Node* curNode)
{
    if (pos < 0)
        return;

    int tmp = (val & (1 << pos));
    if (tmp) tmp = 1;

    if (curNode->child[tmp] == NULL) curNode->child[tmp] = new Node, curNode->child[tmp]->parent = curNode;
    ++curNode->child[tmp]->cnt;
    add(val, pos-1, curNode->child[tmp]);
}

int get(int k, int pos, Node* curNode)
{
    if (pos < 0 || curNode == NULL)
        return 0;

    int t = ((xx & (1 << pos)) == 0);
    if (curNode->child[t] == NULL)
        return get(k, pos - 1, curNode->child[!t]);

    if (curNode->child[t]->cnt < k)
        return get(k - curNode->child[t]->cnt, pos - 1, curNode->child[!t]);

    return get(k, pos - 1, curNode->child[t]) + (1 << pos);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    root = new Node;
    xx = 0;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        add(x, MAXBIT, root);
    }

    for (int i = 0; i < q; ++i)
    {
        scanf("%s %d", s, &x);
        if (s[0] == 'X')
        {
            xx ^= x;
        }
        else
        {
            printf("%d\n", get(x, MAXBIT, root));
        }
    }

    return 0;
}
