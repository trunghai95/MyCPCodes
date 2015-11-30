#include <bits/stdc++.h>

using namespace std;

const int MAX = 5000;
int n, f[MAX], sum, nume, i;

int main()
{
    freopen("in.txt","r",stdin);
    for (int i = 1; i < MAX; ++i)
    {
        sum += i;
        f[i] = sum;
    }
    cin >> n;
    if (n == 1)
    {
        printf("TERM 1 IS 1/1");
    }
    else
    {
        for (i = 1; i < MAX; ++i)
            if (f[i] >= n)
                break;
        ++i;
        nume = n - f[i-2];
        if (i%2 == 0)
            nume = i - nume;
        printf("TERM %d IS %d/%d",n,nume,i-nume);
    }
    while (!cin.eof())
    {
        cin >> n;
        if (n == 1)
        {
            printf("\nTERM 1 IS 1/1");
            continue;
        }
        for (i = 1; i < MAX; ++i)
            if (f[i] >= n)
                break;
        ++i;
        nume = n - f[i-2];
        if (i%2 == 0)
            nume = i - nume;
        printf("\nTERM %d IS %d/%d",n,nume,i-nume);
    }
    return 0;
}
