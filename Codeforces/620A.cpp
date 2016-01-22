#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << max(abs(x2-x1), abs(y2-y1));
    return 0;
}
