//WA
#include <bits/stdc++.h>

using namespace std;

int test, n, a[50010];

struct cmpHeap
{
    bool operator()(int x, int y) { return x < y; }
};

int main()
{
    scanf("%d", &test);

    while (test--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", a+i);
        sort(a, a+n);
        vector<int> cnt;
        cnt.push_back(1);
        for (int i = 1; i < n; ++i)
        {
            if (a[i] == a[i-1])
                ++cnt.back();
            else
                cnt.push_back(1);
        }

        int res = 0;
        priority_queue<int, vector<int>, cmpHeap> heap(cnt.begin(), cnt.end());

        while (heap.size() > 1)
        {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            ++res;
            --a;
            --b;
            if (a)
                heap.push(a);
            if (b)
                heap.push(b);
        }

        if (!heap.empty())
            res += heap.top();

        printf("%d\n", res);
    }
    return 0;
}
