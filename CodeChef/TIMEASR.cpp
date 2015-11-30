#include <bits/stdc++.h>

using namespace std;

struct Time
{
    int h, m;
    Time() {}
    Time(int hh, int mm): h(hh), m(mm) {}
};

const int MAX = 1800000;

int test;
vector<Time> t[MAX + 1];
double a;

int main()
{
    for (int h = 0; h < 12; ++h)
    for (int m = 0; m < 60; ++m)
    {
        int mDeg = m*60000;
        int deg = (h*60 + m)*5000;
        deg = abs(mDeg - deg);
        if (deg > MAX) deg = MAX*2 - deg;

        t[deg].push_back(Time(h,m));
    }


    scanf("%d", &test);

    while (test--)
    {
        char s[10];
        scanf("%s", s);
        int f = 0;
        int aaa = 0, b = 0;

        for (int i = 0; i < strlen(s); ++i)
        {
            if (s[i] == '.')
                f = 1;
            else
            {
                if (!f) aaa = aaa*10 + s[i] - '0';
                else b = b*10 + s[i] - '0', ++f;
            }
        }

        while (f <= 4) { b *= 10; ++f; }

        aaa = aaa*10000 + b;

        for (int j = -83; j <= 83; j++)
        {
            int aa = aaa + j;
            if (aa < 0) aa += 3600000;
            if (aa > MAX) aa = MAX*2 - aa;
            for (int i = 0; i < t[aa].size(); ++i)
                printf("%02d:%02d\n", t[aa][i].h, t[aa][i].m);
        }
    }
    return 0;
}
