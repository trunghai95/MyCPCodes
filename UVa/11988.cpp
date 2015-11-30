#include <bits/stdc++.h>

using namespace std;

int l;
char c[100001];
list<char> res;
list<char>::iterator i;

int main()
{
    while (scanf("%s", c) != EOF)
    {
        res.clear();
        i = res.begin();
        l = strlen(c);
        for (int j = 0; j < l; ++j)
        {
            if (c[j] == '[')
            {
                i = res.begin();
                continue;
            }
            if (c[j] == ']')
            {
                i = res.end();
                continue;
            }
            res.insert(i,c[j]);
        }
        for (i = res.begin(); i != res.end(); ++i)
            printf("%c", *i);
        cout << endl;
    }
    return 0;
}
