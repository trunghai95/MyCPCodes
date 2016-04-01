#include <bits/stdc++.h>

using namespace std;

int n, a[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a+n);

	for (int i = 0; i < n; ++i)
	{
		if (i&1)
			cout << a[n - i/2 - 1] << ' ';
		else
			cout << a[i/2] << ' ';
	}
	return 0;
}