#include <bits/stdc++.h>

using namespace std;

const int maxs = 1e7+7;
int n, i, l1, l2, sum;
char s[maxs], s1[maxs];

int main()
{
    cin >> n >> s >> s1;
    i = 0;
    l1 = strlen(s);
    l2 = strlen(s1);
    while (1)
    {
        if (i >= l1 || i >= l2 || s[i] != s1[i])
            break;
        ++i;
    }
    sum = l1 - i + l2 - i;
    if (sum <= n)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
