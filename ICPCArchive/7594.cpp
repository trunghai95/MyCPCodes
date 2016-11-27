#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
int n, blk, cnt, u, v, res[1000];
bool frPoint[301], frCycle[301], cycle;
string s, t;
vector <pii> li[1000];
vector <int> adj[301];
vector<int> belong[301][301];
map <string, int> name;
map <string, int>::iterator it;
queue <int> que;
bool isPar[301][301];

int put_name(const string& s){
    it = name.find(s);
    if (it != name.end())
        return it->second;
    else {
        ++n;
        isPar[n][n] = true;
        return name[s] = n;
    }
}

void visit(const int& u){
    frCycle[u] = frPoint[u] = true;
    for (int& v : adj[u])
    if (frCycle[v]){
        cycle = true;
        return;
    }
    else
    if (!frPoint[v]){
        visit(v);
        if (cycle)
            return;
    }
    frCycle[u] = false;
}

char str[10];

int main(){
    // ios_base::sync_with_stdio(0);
    scanf("%s", str);
    s = string(str);
    scanf("%s", str);
    t = string(str);
    // cin >> s >> t;
    put_name(s);
    put_name(t);
    scanf("%d", &blk);
    // cin >> blk;
    for (int i = 0; i < blk; ++i){
        scanf("%d", &cnt);
        // cin >> cnt;
        while (cnt--){
            scanf("%s", str);
            s = string(str);
            scanf("%s", str);
            t = string(str);
            // cin >> s >> t;
            u = put_name(s), v = put_name(t);
            li[i].push_back(pii(u, v));
            belong[u][v].push_back(i);
        }
    }

    vector <int> vec = belong[1][2];
    vector <int> vec_rev = belong[2][1];
    for (int& ind : vec){
        res[ind] = 1;
        que.push(ind);
    }
    for (int& ind : vec_rev){
        if (res[ind] == 1){
            printf("No\n");
            // cout << "No";
            return 0;
        }
        res[ind] = -1;
        // que.push(ind);
    }

    while (!que.empty()){
        u = que.front();
        que.pop();
        for (pii node : li[u]){
            for (int i = 1; i <= n; ++i)
            if (i != node.second) {
                if (isPar[i][node.first]) {
                    isPar[i][node.second] = true;
                    vec = belong[i][node.second];
                    for (int& ind : vec)
                    if (res[ind] == -res[u]){
                        printf("No\n");
                        // cout << "No";
                        return 0;
                    }
                    else
                    if (res[ind] == 0){
                        res[ind] = res[u];
                        que.push(ind);
                    }
                }

                if (i != node.first && isPar[node.second][i]) {
                    isPar[node.first][i] = true;
                    vec = belong[node.first][i];
                    for (int& ind : vec)
                    if (res[ind] == -res[u]){
                        printf("No\n");
                        // cout << "No";
                        return 0;
                    }
                    else
                    if (res[ind] == 0){
                        res[ind] = res[u];
                        que.push(ind);
                    }
                }
            }

            if (res[u] == -1)
                continue;
            swap(node.first, node.second);
            vec = belong[node.first][node.second];
            for (int& ind : vec)
            if (res[ind] == res[u]){
                printf("No\n");
                // cout << "No";
                return 0;
            }
            else
            if (res[ind] == 0){
                res[ind] = -res[u];
                //que.push(ind);
            }
        }
    }

    for (int i = 0; i < blk; ++i)
    if (res[i] == 1)
    for (pii& node : li[i])
        adj[node.first].push_back(node.second);

    for (int i = 1; i <= n; ++i)
    if (!frPoint[i]){
        visit(i);
        if (cycle){
            printf("No\n");
            // cout << "No";
            return 0;
        }
    }
    printf("Yes\n");
    // cout << "Yes";

    return 0;
}
