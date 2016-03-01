#include <bits/stdc++.h>

using namespace std;

char s[100010], t[100010];
int cnt[300], cnts[300], res, tmp;

int main()
{
	scanf("%s %s", t, s);
	int lenT = strlen(t), lenS = strlen(s);

	if (lenT < lenS)
	{
		printf("0");
		return 0;
	}

	for (int i = 0; i < lenS; ++i)
		++cnt[t[i]], ++cnts[s[i]];

	bool f = true;
	for (int i = 'a'; i <= 'z' && f; ++i)
	if (cnt[i] > cnts[i])
		f = false;
	else
		tmp += cnts[i] - cnt[i];

	if (f)
		res += (tmp == cnt['?']);

	for (int j = lenS; j < lenT; ++j)
	{
		++cnt[t[j]];
		--cnt[t[j-lenS]];

		f = true;
		tmp = 0;
		for (int i = 'a'; i <= 'z' && f; ++i)
		if (cnt[i] > cnts[i])
			f = false;
		else
			tmp += cnts[i] - cnt[i];

		if (f)
			res += (tmp == cnt['?']);
	}

	printf("%d", res);

	return 0;
}