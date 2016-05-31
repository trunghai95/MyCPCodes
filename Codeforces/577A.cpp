#include <bits/stdc++.h>
using namespace std;
int n, x, i, res;

int main()
{
	cin >> n >> x;
	for (i = 1; i <= n; ++i)
		res += (x % i == 0 && x/i <= n);
	cout << res;
	return 0;
}