#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 7;
char a[MAX], b[MAX], c[MAX];
int la, lb, lc, i, cur, m, mb, mc, cnta[26], cntb[26], cntc[26];

int main()
{
    scanf("%s %s %s", a, b, c);
    la = strlen(a); lb = strlen(b); lc = strlen(c);
    for (i = 0; i < la; ++i) { a[i] -= 'a'; ++cnta[a[i]]; }
    for (i = 0; i < lb; ++i) { b[i] -= 'a'; ++cntb[b[i]]; }
    for (i = 0; i < lc; ++i) { c[i] -= 'a'; ++cntc[c[i]]; }
    cur = i = m = mb = mc = 0;

    while (1)
    {
        int mn = 2e9;
        for (int j = 0; j < 26; ++j)
            if (cntc[j]) mn = min(mn, cnta[j]/cntc[j]);
        cur += mn;
        if (cur > m)
        {
            m = cur;
            mb = i;
            mc = cur - i;
        }
        cur = ++i;
        bool f = 0;
        for (int j = 0; j < 26; ++j)
        {
            if (cnta[j] >= cntb[j]) cnta[j] -= cntb[j];
            else { f = 1; break; }
        }

        if (f) break;
    }

    memset(cnta,0,sizeof(cnta));
    for (i = 0; i < la; ++i) ++cnta[a[i]];

    for (i = 0; i < mb; ++i)
        for (int j = 0; j < lb; ++j)
            printf("%c", b[j] + 'a'), --cnta[b[j]];
    for (i = 0; i < mc; ++i)
        for (int j = 0; j < lc; ++j)
            printf("%c", c[j] + 'a'), --cnta[c[j]];
    for (i = 0; i < 26; ++i)
        for (int j = 0; j < cnta[i]; ++j) printf("%c", i + 'a');

    return 0;
}
