#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[1000010], t[2][10] = {"heavy", "metal"};
int n, b[2][10];
vector<int> p1, p2;
ll res;

void preKMP(int p)
{
	int i = 0, j = b[p][0] = -1;

	while (i < 5)
	{
		while (j >= 0 && t[p][i] != t[p][j]) j = b[p][j];
		++i, ++j;
		b[p][i] = j;
	}
}

void kmp(int p)
{
	int i = 0, j = 0;

	while (i < n)
	{
		while (j >= 0 && t[p][j] != s[i]) j = b[p][j];
		++i, ++j;
		if (j == 5)
		{
			if (p)
				p2.push_back(i - 5);
			else
				p1.push_back(i - 1);
		}
	}
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	preKMP(0); preKMP(1);
	kmp(0); kmp(1);

	if (p1.empty() || p2.empty())
	{
		printf("0");
		return 0;
	}
	int i1 = 0, i2 = 0;
	while (i2 < p2.size() && p2[i2] < p1[0])
		++i2;

	while (i1 < p1.size() && i2 < p2.size())
	{
		// cout << i1 << ' ' << i2 << '\n';
		while (i1 < p1.size() && p1[i1] < p2[i2])
			++i1;
		res += i1;
		--i1;
		++i2;
	}

	printf("%lld", res);
	return 0;
}