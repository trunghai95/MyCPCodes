#include <bits/stdc++.h>

using namespace std;

int com[300][300];

void init()
{
	com['?']['?'] = 10;

	for (int c = '0'; c <= '9'; ++c)
		com[c]['?'] = com['?'][c] = 1, com[c][c] = 1;

	for (int c = 'a'; c <= 'g'; ++c)
	{
		com[c]['?'] = com['?'][c] = 4;
		for (int i = 0; i < 4; ++i)
		{
			com[c][c+i] = com[c+i][c] = 4 - i;
			com[c][c-'a'+'0'+i] = com[c-'a'+'0'+i][c] = 1;
		}
	}
}

int main()
{
	init();

	string s1, s2;
	cin >> s1 >> s2;

	int res = 1;

	for (int i = 0; i < s1.length(); ++i)
	{
		res *= com[s1[i]][s2[i]];
	}

	cout << res;
	return 0;
}