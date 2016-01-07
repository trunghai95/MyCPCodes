#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
bool ck[10001];

void init()
{
    for (int i = 2; i <= 10000; ++i)
    if (!ck[i])
    {
        primes.push_back(i);
        for (int j = i*i; j <= 10000; j += i)
            ck[j] = true;
    }

//    printf("size: %d\n", primes.size());
//    for (int i = 0; i < primes.size(); ++i)
//        printf("%d ", primes[i]);
//    printf("\n");
}

int test, n, a[10000];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    init();
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        int res = 2e9;
        for (int i = 0; i < primes.size() && res; ++i)
        {
            int last = (a[0] - 1) / primes[i] * primes[i] + primes[i];
            int cnt = last - a[0];
            for (int j = 1; j < n; ++j)
            {
                last = max(last, (a[j] - 1) / primes[i] * primes[i] + primes[i]);
                cnt += last - a[j];
            }

            if (cnt < res)
            {
                res = cnt;
//                printf("%d %d\n", primes[i], res);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
