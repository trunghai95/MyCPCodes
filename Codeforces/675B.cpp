#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, a, b, c, d;
ll res;

int main()
{
	cin >> n >> a >> b >> c >> d;

	for (int i = 1; i <= n; ++i)
	{
		int x = i+a-d, y = i+b-c, z = i+a+b-c-d;
		if (x >= 1 && x <= n && y >= 1 && y <= n && z >= 1 && z <= n
			&& z+c == x+b && z+d == y+a)
			++res;
	}

	res *= n;
	cout << res;
	return 0;
}