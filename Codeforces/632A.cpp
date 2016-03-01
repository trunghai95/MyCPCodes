#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll res, cur;
int n, p;
string s[50];

int main()
{
	cin >> n >> p;

	for (int i = 0; i < n; ++i)
		cin >> s[i];

	for (int i = n-1; i >= 0; --i)
	{
		if (s[i] == "half")
		{
			res += cur * p;
			cur *= 2;
		}
		else
		{
			res += cur * p + p / 2;
			cur = cur * 2 + 1;
		}
	}

	cout << res;
	return 0;
}