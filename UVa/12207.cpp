#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int p, c, x, test;
char s[5];

int main()
{
	while (++test)
	{
		scanf("%d %d", &p, &c);

		if (p == 0 && c == 0)
			return 0;

		printf("Case %d:\n", test);

		list<int> l;
		p = min(p, c);

		for (int i = 1; i <= p; ++i)
			l.push_back(i);

		for (int i = 0; i < c; ++i)
		{
			scanf("%s", s);

			if (s[0] == 'E')
			{
				scanf("%d", &x);
				for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
				if (*it == x)
				{
					l.erase(it);
					break;
				}

				l.push_front(x);
			}
			else
			{
				printf("%d\n", l.front());
				l.push_back(l.front());
				l.pop_front();
			}
		}
	}
	return 0;
}