#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, cnt1[5], cnt2[5], res;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < 5; ++i)
		cnt1[i] = n/5 + (n%5 >= i);
	for (int i = 0; i < 5; ++i)
		cnt2[i] = m/5 + (m%5 >= i);
	--cnt1[0];
	--cnt2[0];

	res = cnt1[0] * cnt2[0];
	for (int i = 1; i < 5; ++i)
		res += cnt1[i] * cnt2[5-i];
	cout << res;
	return 0;
}