#include <bits/stdc++.h>

using namespace std;

string a[3], c[6], s;
int n;

void proc(string &str)
{
	int i = 0, j = 0;

	while (j < str.length())
	{
		if (str[j] >= 'a' && str[j] <= 'z')
			str[i] = str[j], ++i;
		else if (str[j] >= 'A' && str[j] <= 'Z')
			str[i] = str[j] + 32, ++i;

		++j;
	}
	str.resize(i);
}

void solve()
{
	for (int i = 0; i < 6; ++i)
	if (s == c[i])
	{
		cout << "ACC\n";
		return;
	}

	cout << "WA\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> a[0] >> a[1] >> a[2];
	for (int i = 0; i < 3; ++i)
		proc(a[i]);
	c[0] = a[0] + a[1] + a[2];
	c[1] = a[0] + a[2] + a[1];
	c[2] = a[1] + a[0] + a[2];
	c[3] = a[1] + a[2] + a[0];
	c[4] = a[2] + a[0] + a[1];
	c[5] = a[2] + a[1] + a[0];

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		proc(s);
		solve();
	}
	return 0;
}