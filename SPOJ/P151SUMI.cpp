#include <bits/stdc++.h>

using namespace std;

string team[2], s;
int goal[2], n, tc;

int main()
{
    cin >> n;
    tc = 0;
    memset(goal, 0, sizeof(goal));
    while (n-- > 0)
    {
        cin >> s;
        if (tc < 2)
        {
            team[tc] = s;
            ++tc;
        }
        if (s == team[0])
            ++goal[0];
        else
            ++goal[1];
    }
    if (goal[0] > goal[1])
        cout << team[0];
    else
        cout << team[1];
    return 0;
}
