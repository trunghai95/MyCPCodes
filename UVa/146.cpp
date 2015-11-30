#include <bits/stdc++.h>

using namespace std;

char s[100];

int main()
{
    while (1)
    {
        scanf("%s",s);
        if (s[0] == '#')
            return 0;
        if (!next_permutation(s,s+strlen(s)))
            printf("No Successor\n");
        else
            printf("%s\n",s);
    }
    return 0;
}
