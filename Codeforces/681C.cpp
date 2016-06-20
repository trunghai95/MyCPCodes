#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define INSERT 0
#define GET 1
#define REMOVE 2

int n;
map<int,int> cnt;
map<int,int>::iterator it;
vector<pii> res;
char s[10];
int x;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);

		if (!strcmp(s, "removeMin"))
		{
			if (cnt.size() == 0)
				res.push_back(pii(INSERT, 0));
			else
			{
				it = cnt.begin();
				if (--(it->second) == 0)
					cnt.erase(it);
			}
			res.push_back(pii(REMOVE, 0));
		}
		else if (!strcmp(s, "insert"))
		{
			scanf("%d", &x);
			++cnt[x];
			res.push_back(pii(INSERT, x));
		}
		else
		{
			scanf("%d", &x);
			while (cnt.size() > 0)
			{
				it = cnt.begin();
				if (it->first < x)
				{
					for (int j = 0; j < it->second; ++j)
						res.push_back(pii(REMOVE, it->first));
					cnt.erase(it);
				}
				else
					break;
			}

			if (cnt.empty() || cnt.begin()->first > x)
				res.push_back(pii(INSERT, x)), ++cnt[x];
			res.push_back(pii(GET, x));
		}
	}

	printf("%d\n", res.size());
	for (int i = 0; i < (int)res.size(); ++i)
	{
		if (res[i].first == INSERT)
			printf("insert %d\n", res[i].second);
		else if (res[i].first == GET)
			printf("getMin %d\n", res[i].second);
		else
			printf("removeMin\n");
	}
	return 0;
}