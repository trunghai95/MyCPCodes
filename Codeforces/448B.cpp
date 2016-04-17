#include <bits/stdc++.h>

using namespace std;

string s, t;

bool automaton()
{
	int it = 0;
	for (int is = 0; is < s.length(); ++is)
	{
		if (s[is] == t[it])
		{
			++it;
			if (it == t.length())
				return true;
		}
	}

	return false;
}

bool array()
{
	int cnts[300], cntt[300];
	memset(cnts, 0, sizeof(cnts));
	memset(cntt, 0, sizeof(cntt));

	for (int i = 0; i < s.length(); ++i)
		++cnts[s[i]];

	for (int i = 0; i < t.length(); ++i)
		++cntt[t[i]];

	for (int i = 'a'; i <= 'z'; ++i)
	if (cnts[i] < cntt[i])
		return false;

	return true;
}

int main()
{
	cin >> s >> t;

	if (automaton())
		cout << "automaton";
	else if (array())
	{
		if (s.length() == t.length())
			cout << "array";
		else
			cout << "both";
	}
	else
		cout << "need tree";
	return 0;
}