#include <bits/stdc++.h>

using namespace std;

int n;

bool cmpheap(const int& x, const int& y) { return x > y; }

int main()
{
    //freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) != EOF)
    {
        int isS = 1, isQ = 1, isPQ = 1;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        int t, x;

        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &t, &x);
            if (t == 1)
            {
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else
            {
                if (s.empty() || s.top() != x)
                    isS = 0;
                else s.pop();

                if (q.empty() || q.front() != x)
                    isQ = 0;
                else q.pop();

                if (pq.empty() || pq.top() != x)
                    isPQ = 0;
                else pq.pop();
            }
        }

        t = isS + isQ + isPQ;
        if (!t)
            printf("impossible\n");
        else if (t > 1)
            printf("not sure\n");
        else
        {
            if (isS)
                printf("stack\n");
            else if (isQ)
                printf("queue\n");
            else printf("priority queue\n");
        }
    }
    return 0;
}
