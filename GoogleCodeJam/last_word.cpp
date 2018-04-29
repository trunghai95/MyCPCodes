#include <bits/stdc++.h>

using namespace std;

int test;
char s[1010];

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%s", s);
		int n = strlen(s);
		vector<string> res;
		res.push_back(string(1, s[0]));
		for (int i = 1; i < n; ++i)
		{
			string s1 = res.back() + s[i];
			string s2 = string(1, s[i]) + res.back();
			if (s1 > s2)
				res.push_back(s1);
			else
				res.push_back(s2);
		}

		printf("Case #%d: %s\n", tt, res.back().c_str());
	}
	return 0;
}