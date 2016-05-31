#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n, res;
pii op[20];
char s[20];

bool check(int x)
{
	for (int i = 0; i < n; ++i)
	{
		if (op[i].first == 'A')
			x += op[i].second;
		else if (op[i].first == 'S')
		{
			x -= op[i].second;
			if (x < 0)
				return true;
		}
		else if (op[i].first == 'M')
			x *= op[i].second;
		else
		{
			if (x % op[i].second != 0)
				return true;
			x /= op[i].second;
		}
	}
	return false;
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d", s, &op[i].second);
		op[i].first = s[0];
	}

	for (int i = 1; i <= 100; ++i)
		res += check(i);

	printf("%d", res);
	return 0;
}