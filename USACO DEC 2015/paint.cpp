#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a <= c && b >= d)
        cout << b - a;
    else if (c <= a && d >= b)
        cout << d - c;
    else if (b <= c || d <= a)
        cout << b - a + d - c;
    else cout << max(b,d) - min(a,c);

    return 0;
}
