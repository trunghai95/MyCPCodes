#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll P1 = 1234567, P2 = 123456, P3 = 1234;

ll n;

int main()
{
	cin >> n;
	ll a, b;

	a = 0;

	while (a*P1 <= n)
	{
		b = 0;
		while (a*P1 + b*P2 <= n)
		{
			if ((n - a*P1 - b*P2) % P3 == 0)
			{
				cout << "YES";
				return 0;
			}
			++b;
		}
		++a;
	}
	cout << "NO";
	return 0;
}