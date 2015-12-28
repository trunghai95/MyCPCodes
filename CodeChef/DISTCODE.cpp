#include <bits/stdc++.h>

using namespace std;

bool ck[800];
int test;
char s[10010];

int main()
{
    scanf("%d", &test);

    while (test--)
    {
        memset(ck, 0, sizeof(ck));

        scanf("%s", s);
        int len = strlen(s);
        int res = 0;
        for (int i = 1; i < len; ++i)
        {
            int tmp = (s[i-1] - 'A') * 26 + s[i] - 'A';
            if (!ck[tmp])
                ++res, ck[tmp] = true;
        }
        printf("%d\n", res);
    }
    return 0;
}
