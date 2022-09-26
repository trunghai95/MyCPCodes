#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int test, n;
bool mark[10];
char s[MAXN];

int main() {
    scanf("%d\n", &test);
    while (test --> 0) {
        scanf("%s\n", s);
        memset(mark, 0, sizeof(mark));
        n = strlen(s);
        int i = n-1;
        while (i >= 0) {
            if (mark[s[i]-'0']) {
                break;
            }
            mark[s[i]-'0'] = true;
            i--;
        }
        printf("%d\n", i+1);
    }
    return 0;
}