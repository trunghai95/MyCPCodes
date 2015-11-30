#include <bits/stdc++.h>

using namespace std;

int test, n, l;
char s[100];

int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n >> s;
        l = strlen(s);
        if (!next_permutation(s,s+l))
            cout << n << " BIGGEST" << endl;
        else
            cout << n << ' ' << s << endl;
    }
    return 0;
}
