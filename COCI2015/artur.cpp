#include <bits/stdc++.h>

using namespace std;

struct Line
{
    int x1, y1, x2, y2, id;
};

int n;
Line line[5010];

bool cmp(const Line& x, const Line& y)
{
    if (x.x2 < y.x1 || x.x1 > y.x2)
        return false;

    return max(y.y1, y.y2) > min(x.y1, x.y2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;
        line[i].id = i;
        if (line[i].x1 > line[i].x2)
            swap(line[i].x1, line[i].x2), swap(line[i].y1, line[i].y2);
        else if (line[i].x1 == line[i].x2 && line[i].y1 > line[i].y2)
            swap(line[i].x1, line[i].x2), swap(line[i].y1, line[i].y2);
    }

    sort(line + 1, line + 1 + n, cmp);

    for (int i = 1; i <= n; ++i)
        cout << line[i].id << ' ';

    return 0;
}
