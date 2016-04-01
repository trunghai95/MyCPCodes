#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll r, g, b, k;
int test;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> test;

	while (test--)
	{
		cin >> r >> g >> b >> k;
		cout << min(r, k-1) + min(g, k-1) + min(b, k-1) + 1 << '\n';
	}
	return 0;
}