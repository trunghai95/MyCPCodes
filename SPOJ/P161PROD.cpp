#include <bits/stdc++.h>

using namespace std;

string key[3] = { "qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
char mp[300];
string s;

int main()
{
	cin >> s;

	for (int i = 0; i < 3; ++i)
	{
		int len = key[i].length();
		for (int j = 0; j < len; ++j)
		{
			if (s[0] == 'L')
				mp[key[i][j]] = key[i][(j + 1)%len];
			else
				mp[key[i][j]] = key[i][(j - 1 + len ) % len];
		}
	}

	cin >> s;
	for (int i = 0; i < s.length(); ++i)
		cout << mp[s[i]];
	return 0;
}