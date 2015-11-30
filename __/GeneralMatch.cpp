#include <bits/stdc++.h>

using namespace std;

#define maxn 411
bool a[maxn][maxn];
int match[maxn], b[maxn], T[maxn];
bool inQ[maxn], inPath[maxn], mark[maxn];
int n, start, finish;
queue<int> q;

void init() {memset(match, 0, sizeof(match));}
void initBFS(){
    while (!q.empty()) q.pop();
    q.push(start);
    memset(inQ, 0, sizeof(inQ));
    inQ[start] = true;
    memset(T, 0, sizeof(T));
    for(int i = 1; i <= n; ++i) b[i] = i;
    finish = 0;
}
void push(int v) {q.push(v); inQ[v] = true;}
int LCA(int u, int v){
    memset(inPath, 0, sizeof(inPath));
    while (true){
        u = b[u];
        inPath[u] = true;
        if (u == start) break;
        u = T[match[u]];
    }
    while (true){
        v = b[v];
        if (inPath[v]) break;
        v = T[match[v]];
    }
    return v;
}
void resetTrace(int x, int lca){
    int v = x;
    while (b[v] != lca){
        int u = match[v];
        mark[b[v]] = mark[b[u]] = true;
        v = T[u];
        if (b[v] != lca) T[v] = u;
    }
}
void shrink(int u, int v){
    memset(mark, 0, sizeof(mark));
    int lca = LCA(u, v);
    resetTrace(u, lca); resetTrace(v, lca);
    if (b[u] != lca) T[u] = v;
    if (b[v] != lca) T[v] = u;
    for (int i = 1; i <= n; ++i)
        if (mark[b[i]]) b[i] = lca;
    for(int i = 1; i <= n; ++i)
        if (!inQ[i] && b[i] == lca) push(i);
}
void findPath(){
    initBFS();
    while (!q.empty()){
        int u = q.front(); q.pop();
        for(int v = 1; v <= n; ++v)
        if (T[v] == 0 && a[u][v] && b[u] != b[v]){
            if (match[v] == 0)
            {
                T[v] = u;
                finish = v;
                return;
            }
            if (v == start || T[match[v]] != 0) shrink(u, v);
            else {
                T[v] = u;
                push(match[v]);
            }
        }
    }
}
void enlarge(){
    do{
        int v = T[finish];
        int next = match[v];
        match[v] = finish;
        match[finish] = v;
        finish = next;
    }while (finish);
}
int solve(){
    memset(match, 0, sizeof(match));
    memset(b, 0, sizeof(b));
    memset(T, 0, sizeof(T));
    for(int u = 1; u <= n; ++u)
    if (match[u] == 0){
        start = u;
        findPath();
        if (finish) enlarge();
    }
    //
    int ret = 0;
    for(int u = 1; u <= n; ++u)
        if (match[u] > u)
            ++ret; //cout << u - match[u]
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);


    return 0;
}
