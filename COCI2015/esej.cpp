#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    a = max(a, b/2 + (b&1));

    char s[20] = "abcdefghij";

    for (int i = 1; i < a; ++i)
    {
        printf("%s ", s);
        next_permutation(s, s+10);
    }

    printf("%s", s);

    return 0;
}
