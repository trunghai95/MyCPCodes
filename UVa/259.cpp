#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int e[38][38], f, mf, l;
char s[50], ctmp;
int p[38];
bool ck[38];

void aug(int v, int minEdge)
{
    if (v == 0)
    {
        f = minEdge;
        return;
    }
    else if (p[v] != -1)
    {
        aug(p[v], min(minEdge,e[p[v]][v]));
        e[p[v]][v] -= f;
        e[v][p[v]] += f;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    memset(e,0,sizeof(e));
    memset(p,-1,sizeof(p));
    mf = 0;
    for (int i = 27; i <= 36; ++i) e[i][37] = 1;
    while (!cin.eof())
    {
        cin.getline(s, 50);
        if ((l = strlen(s)) < 2)
        {
            while (1)
            {
                f = 0;
                memset(ck,0,sizeof(ck));
                queue<int> q;
                ck[0] = 1;
                q.push(0);
                while (!q.empty())
                {
                    int u = q.front(); q.pop();
                    if (u == 37) break;
                    for (int v = 0; v <= 37; ++v)
                    if (e[u][v] > 0 && !ck[v]) ck[v] = 1, p[v] = u, q.push(v);
                }
                aug(37,INF);
                if (f == 0) break;
                mf -= f;
            }

            if (mf)
                printf("!\n");
            else
            {
                for (int i = 27; i <= 36; ++i)
                {
                    if (e[i][37])
                        printf("_");
                    else for (int j = 1; j <= 26; ++j) if (e[i][j])
                    {
                        printf("%c",j+'A'-1);
                        break;
                    }
                }
                printf("\n");
            }

            memset(e,0,sizeof(e));
            mf = 0;
            for (int i = 27; i <= 36; ++i) e[i][37] = 1;
        }
        else
        {
            e[0][s[0]-'A'+1] = s[1]-'0';
            for (int i = 3; i < l-1; ++i)
                e[s[0]-'A'+1][s[i]-'0'+27] = 1;
            mf += s[1]-'0';
        }
    }
    return 0;
}
