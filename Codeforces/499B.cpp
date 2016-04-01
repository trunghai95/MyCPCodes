#include <bits/stdc++.h>

using namespace std;

map<string,string> mp;
int n, m;
string a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		if (a.length() > b.length())
			mp[a] = b;
		else
			mp[a] = a;
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		cout << mp[a] << ' ';
	}
	return 0;
}