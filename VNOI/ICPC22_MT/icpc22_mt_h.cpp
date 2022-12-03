#include <stdio.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cstring>

using namespace std;

#define ll long long
#define pli pair<ll,int>
const int MAXN = 1e5+5;
int n, m, k, u, v;
vector<pli> adj[MAXN];
ll dist[MAXN], d;
priority_queue<pli, vector<pli>, greater<pli> > heap;
pli cur, nxt;

int main() {
    scanf("%d %d", &n, &m);
    while (m --> 0) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(pli(0, v));
        adj[v].push_back(pli(0, u));
    }
    scanf("%d", &k);
    while (k --> 0) {
        scanf("%d %d %d", &m, &u, &v);
        adj[u].push_back(pli(m, v));
        adj[v].push_back(pli(m, u));
    }

    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    heap.push(pli(0, 1));

    while (!heap.empty()) {
        cur = heap.top();
        heap.pop();
        // printf("%d %lld\n", cur.second, cur.first);
        if (cur.second == n) {
            break;
        }
        if (cur.first > dist[cur.second]) {
            continue;
        }
        for (int i = 0; i < adj[cur.second].size(); i++) {
            nxt = adj[cur.second][i];
            v = nxt.second;
            d = max(cur.first + 1, nxt.first);
            // printf("%d %lld %lld\n", v, nxt.first, d);
            if (dist[v] == -1 || dist[v] > d) {
                dist[v] = d;
                heap.push(pli(d, v));
            }
        }
    }

    printf("%lld\n", dist[n]);
    return 0;
}