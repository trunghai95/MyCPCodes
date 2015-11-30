#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct Seg
{
    int x1, y1, x2, y2;
    Seg(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
    void Swap() { swap(x1,y1), swap(x2,y2); }
    int len() { return abs(x2 - x1 + y2 - y1); }
};

int n, x, y, xx, yy;
vector<Seg> segs;

int cut(int xx, int yy)
{
    Seg a = segs[xx], b = segs[yy];
    if (a.x1 != a.x2) a.Swap(), b.Swap();

    if (b.x1 == b.x2)
    {
        if (b.x1 != a.x1)
            return -1;

        if (b.y2 == a.y1 || b.y1 == a.y1)
            return a.len() + b.len();

        return -1;
    }

    if ((b.x2 == a.x1 && b.y2 == a.y1) || (b.x1 == a.x1 && b.y1 == a.y1))
        return a.len() + b.len();

    if ((b.x2 - a.x1)*(b.x1 - a.x1) <= 0 && (b.y2 - a.y1)*(b.y2 - a.y2) <= 0)
    {
        int x = a.x1, y = b.y1;
        return abs(a.y2 - y) + abs(b.x1 - x);
    }

    return -1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    cin >> x >> y;
    if (n == 1) { cout << 0; return 0; }
    segs.push_back(Seg(x,y,x,y));

    for (int i = 1; i < n; ++i)
    {
        cin >> x >> y;
        Seg s = segs.back();
        if ((s.x1 == s.x2 && s.x1 == x) || (s.y1 == s.y2 && s.y1 == y))
        {
            segs.back().x2 = x;
            segs.back().y2 = y;
        }
        else segs.push_back(Seg(s.x2,s.y2,x,y));
    }

    n = segs.size();

    int res = 2e9, sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += segs[i].len();
        if (i < 3) continue;

        int j, tmp = segs[i-1].len() + segs[i-2].len(), tt;

        for (j = i - 3; j >= 0; --j)
        {
            if ((tt = cut(j, i)) != -1)
            {
                tmp += tt;
                break;
            }
            tmp += segs[j].len();
        }

        if (j >= 0) res = min(res, tmp);
    }

    res = min(res, sum);

    cout << res;

    return 0;
}
