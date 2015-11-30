#include <bits/stdc++.h>

using namespace std;

int n, resi;
char s[100][6], ress[6];
char t[6] = "ABCDE";

int dist(char x[6], char y[6])
{
    int posx[5], posy[5], res = 0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            if (x[j] == t[i])
                posx[i] = j;
            if (y[j] == t[i])
                posy[i] = j;
        }

    for (int i = 0; i < 4; ++i)
        for (int j = i+1; j < 5; ++j)
        {
            if ((posx[j]-posx[i])*(posy[j]-posy[i]) < 0)
                ++res;
        }

    return res;
}

int main()
{
    while (1)
    {
        cin >> n;
        if (n == 0) return 0;
        resi = 1e9;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        char tmp[6] = "ABCDE";
        int sum;
        do
        {
            sum = 0;
            for (int i = 0; i < n; ++i)
                sum += dist(tmp,s[i]);
            if (sum < resi)
            {
                resi = sum;
                strcpy(ress,tmp);
            }
        }
        while (next_permutation(tmp,tmp+5));

        printf("%s is the median ranking with value %d.\n",ress,resi);
    }
    return 0;
}
