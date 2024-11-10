#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Node {
    int id;
    int cost;
    ll flag;
};

struct cmp {
    bool operator()(Node x, Node y) {
        return x.cost > y.cost;
    }
};

void printFlag(ll flag) {
    while (flag) {
        printf("%lld", flag & 1);
        flag >>= 1;
    }
    printf("\n");
}

const int MAXN = 300005;
const int MAXM = 45;
int n, m, c[MAXN], x[MAXM], cost[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        c[i]--;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x[i]);
    }

    memset(cost, -1, sizeof(cost));
    priority_queue<Node, vector<Node>, cmp> heap;
    ll flag = 1LL << c[0];
    cost[0] = x[c[0]];
    for (int i = 1; i < n; i++) {
        if (c[i] == c[i-1] && !(flag & (1LL << c[i]))) {
            flag |= 1LL << c[i];
            cost[0] += x[c[i]];
        }
    }
    heap.push(Node{0, cost[0], flag});
    
    while (!heap.empty()) {
        Node node = heap.top();
        heap.pop();
        printf("pop %d %d \n", node.id, node.cost);
        printFlag(node.flag);
        if (node.id == n-1) {
            break;
        }
        if (node.cost > cost[node.id]) {
            continue;
        }
        for (int i = 1; i <= 2; i++) {
            int adj = node.id + i;
            if (adj >= n) {
                continue;
            }
            int d;
            if (node.flag & (1 << c[adj])) {
                d = node.cost;
            } else {
                d = node.cost + x[c[adj]];
            }
            if (cost[adj] >= 0 && cost[adj] <= d) {
                continue;
            }
            cost[adj] = d;
            heap.push(Node{adj, d, node.flag | (1LL << c[adj])});
        }
    }
    printf("%d\n", cost[n-1]);
    return 0;
}