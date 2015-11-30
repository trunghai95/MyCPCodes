#include <bits/stdc++.h>

using namespace std;

#define CW 0
#define CCW 1

struct Wheel
{
    int tu, mau, dir, x, y, r;
    Wheel(): dir(-1) {}
    Wheel(int xx, int yy, int rr):
        x(xx), y(yy), r(rr), dir(-1) {}
};

int test, n;
Wheel w[1000];

int dist(int x, int y)
{
    return (w[x].x - w[y].x)*(w[x].x - w[y].x) + (w[x].y - w[y].y)*(w[x].y - w[y].y);
}

int gcd(int x, int y)
{
    if (!x || !y) return (x+y);
    return (x>y)?gcd(x%y,y):gcd(y%x,x);
}

int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 0, x, y, r; i < n; ++i)
        {
            cin >> x >> y >> r;
            w[i] = Wheel(x, y, r);
        }

        w[0].dir = CW;
        w[0].tu = 1; w[0].mau = 1;

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int i = 0; i < n; ++i)
            {
                if (w[i].dir == -1 && dist(i,u) == (w[i].r + w[u].r)*(w[i].r + w[u].r))
                {
                    w[i].dir = 1 - w[u].dir;
                    w[i].tu = w[u].r * w[u].tu;
                    w[i].mau = w[i].r * w[u].mau;
                    int g = gcd(w[i].tu, w[i].mau);
                    w[i].tu /= g;
                    w[i].mau /= g;
                    q.push(i);
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (w[i].dir == -1)
                cout << "not moving\n" << endl;
            else
            {
                cout << w[i].tu;
                if (w[i].mau != 1) cout << '/' << w[i].mau;
                if (w[i].dir == CW) cout << " clockwise\n";
                else cout << " counterclockwise\n";
            }
        }
    }
    return 0;
}
