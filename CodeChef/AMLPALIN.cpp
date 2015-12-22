#include <bits/stdc++.h>

using namespace std;

int test, n;
int cnt[4];
char s[5];

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);
    while (test--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            if (s[0] == 'a')
            {
                if (s[1] == 'a') ++cnt[0];
                else ++cnt[1];
            }
            else
            {
                if (s[1] == 'a') ++cnt[2];
                else ++cnt[3];
            }
        }

        vector<int> res;

        while (cnt[0] > 1)
        {
            res.push_back(0);
            cnt[0] -= 2;
        }

        while (cnt[1] && cnt[2])
        {
            res.push_back(1);
            --cnt[1], --cnt[2];
        }

        while (cnt[3] > 1)
        {
            res.push_back(3);
            cnt[3] -= 2;
        }

        for (int i = 0; i < res.size(); ++i)
        {
            if (res[i] == 0) printf("aa");
            else if (res[i] == 1) printf("ab");
            else if (res[i] == 3) printf("bb");
        }

        if (cnt[0]) printf("aa");
        else if (cnt[3]) printf("bb");

        for (int i = res.size() - 1; i >= 0; --i)
        {
            if (res[i] == 0) printf("aa");
            else if (res[i] == 1) printf("ba");
            else if (res[i] == 3) printf("bb");
        }
        printf("\n");
    }
    return 0;
}
