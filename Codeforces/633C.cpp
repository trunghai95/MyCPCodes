#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1000000007;

int n, m;
ll hash[10009], pow26[10009];
char s[10009], w[1009];
map<ll, string> mp;
vector<int> p;
int beg[10009];

ll hashW()
{
	ll res = 0;
	int len = strlen(w);
	for (int i = 0; i < len; ++i)
		res = (res * 27 + (w[i] <= 'Z' ? w[i] + 32 : w[i]) - 'a' + 1) % MODD;
	// printf("%s %lld\n", w, res);
	return res;
}

void hashS()
{
	ll res = 0;
	for (int i = 0; i < n; ++i)
		res = (res * 27 + s[i] - 'a' + 1) % MODD, hash[i] = res;
	pow26[0] = 1;
	for (int i = 1; i <= n; ++i)
		pow26[i] = (pow26[i-1] * 27) % MODD;
}

ll hashSeg(int i, int j)
{
	if (!i)
		return hash[j];
	return (hash[j] - hash[i-1] * pow26[j - i + 1] + MODD * MODD) % MODD;
}

int main()
{
	scanf("%d %s %d", &n, s, &m);

	for (int i = 0; i < m; ++i)
	{
		scanf("%s", w);
		mp[hashW()] = string(w);
	}

	reverse(s, s + n);
	hashS();

	memset(beg, -1, sizeof(beg));
	for (int i = 0; i < n; ++i)
	{
		map<ll, string>::iterator it = mp.find(hash[i]);
		if (it != mp.end())
		{
			beg[i] = 0;
			p.push_back(i);
			// printf("%d full\n", i);
		}
		else
		{
			for (int j = 0; j < p.size(); ++j)
			{
				it = mp.find(hashSeg(p[j] + 1, i));
				if (it != mp.end())
				{
					beg[i] = p[j] + 1;
					p.push_back(i);
					break;
				}
			}
		}
	}

	int i = n - 1;
	while (beg[i])
	{
		printf("%s ", mp[hashSeg(beg[i], i)].c_str());
		i = beg[i] - 1;
	}
	printf("%s", mp[hash[i]].c_str());
	return 0;
}