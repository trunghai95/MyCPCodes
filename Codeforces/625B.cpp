#include <bits/stdc++.h>

using namespace std;

string s1, s2;
vector<int> v;

int main()
{
	cin >> s1 >> s2;

	if (s1.length() < s2.length())
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= s1.length() - s2.length(); ++i)
	{
		bool f = true;
		for (int j = 0; j < s2.length() && f; ++j)
			if (s1[i+j] != s2[j])
				f = false;

		if (f)
			v.push_back(i);
	}

	if (v.empty())
	{
		cout << 0;
		return 0;
	}

	int res1 = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		++res1;
		int p = v[i] + s2.length();
		while (i < v.size() && v[i] < p) ++i;
		--i;
	}

	cout << res1;

	return 0;
}