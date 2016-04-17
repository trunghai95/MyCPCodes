#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
const ll BASE = 5;

int n, m, len;
char s[1000000];
set<ll> st;

ll hash()
{
	ll res = 0;
	for (int i = 0; i < len; ++i)
		res = (res * BASE + s[i] - 'a' + 1);
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		len = strlen(s);
		st.insert(hash());
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%s", s);
		len = strlen(s);
		bool found = false;
		for (int j = 0; j < len; ++j)
		{
			s[j] = (s[j] - 'a' + 1) % 3 + 'a';
			if (st.find(hash()) != st.end())
			{
				found = true;
				break;
			}
			s[j] = (s[j] - 'a' + 1) % 3 + 'a';
			if (st.find(hash()) != st.end())
			{
				found = true;
				break;
			}
			s[j] = (s[j] - 'a' + 1) % 3 + 'a';
		}
		if (found)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}