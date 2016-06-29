#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cntDig(ll x)
{
	if (x == 0)
		return 1;
	int res = 0;
	while (x)
	{
		++res;
		x /= 7;
	}
	return res;
}

ll n, m;
int cntn, cntm;
bool ck[7];

bool check(ll a, ll b)
{
	if (a == b)
		return false;
	memset(ck, 0, sizeof(ck));
	
	for (int i = 0; i < cntn; ++i)
	{
		if (ck[a % 7])
			return false;
		ck[a % 7] = true;
		a /= 7;
	}
	for (int i = 0; i < cntm; ++i)
	{
		if (ck[b % 7])
			return false;
		ck[b % 7] = true;
		b /= 7;
	}
	return true;
}

int main()
{
	cin >> n >> m;
	cntn = cntDig(n-1);
	cntm = cntDig(m-1);
	if (cntn + cntm > 7)
	{
		printf("0");
		return 0;
	}

	int res = 0;

	for (ll a = 0; a < n; ++a)
	for (ll b = 0; b < m; ++b)
		res += check(a, b);

	cout << res;
	return 0;
}