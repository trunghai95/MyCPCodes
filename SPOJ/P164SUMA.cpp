#include <bits/stdc++.h>

using namespace std;

int n;
string s;
map<string, int> cnt;

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> s, ++cnt[s];

	for (map<string,int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
	{
		if (it->second > n/2)
			cout << it->first << '\n';
	}
	return 0;
}