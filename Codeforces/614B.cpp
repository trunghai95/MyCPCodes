#include <bits/stdc++.h>

using namespace std;

int n;
char s[100010];

int check()
{
    int len = strlen(s);
    if (len == 1 && s[0] == '0')
        return -1;
    if (s[0] != '1')
        return -2;

    for (int i = 1; i < len; ++i)
        if (s[i] != '0')
            return -2;
    return len - 1;
}

int main()
{
    unsigned long long res = 1;
    while (1)
    {
        if (res > 1000000000000000000)
            break;
        if (res >= 1 && res <= 1000000000000000000)
            cout << res << ' ';
        res *= 999999999;
    }
    return 0;




    scanf("%d", &n);
    int trail = 0;
    char pre[100010];

    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        int d = check();
        if (d == -2)
            strcpy(pre, s);
        else if (d == -1)
        {
            printf("0");
            return 0;
        }
        else trail += d;
    }

    if (strlen(pre) > 0)
        printf("%s", pre);
    else printf("1");
    for (int i = 0; i < trail; ++i)
        printf("0");
    return 0;
}
