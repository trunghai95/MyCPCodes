#include <bits/stdc++.h>

using namespace std;

char s[1000010], t[1000010];
string res1, res2;
int cnt[10], len;

int numDigits(int x)
{
	if (x == 0) return 1;
	return (int) log10((double) x) + 1;
}

int findOriLen()
{
	for (int i = len; i >= 0; --i)
	{
		int num = numDigits(i);
		if (num + i == len)
			return i;
	}
	return 0;
}

void red(int tmp)
{
	if (!tmp)
		--cnt[0];
	else while (tmp)
		--cnt[tmp%10], tmp /= 10;
}

int main()
{
	scanf("%s %s", s, t);
	len = strlen(s);

	for (int i = 0; i < len; ++i)
		++cnt[s[i] - '0'];

	int oriLen = findOriLen();
	red(oriLen);

	if (oriLen == strlen(t))
	{
		printf("%s", t);
		return 0;
	}

	len = strlen(t);

	for (int i = 0; i < len; ++i)
		--cnt[t[i] - '0'];

	int type = 0;
	for (int i = 1; i < len; ++i)
	if (t[i] < t[0])
	{
		type = -1;
		break;
	}
	else if (t[i] > t[0]) break;

	int mn = 0;
	for (int i = 1; i < 10; ++i)
	if (cnt[i])
	{
		mn = i;
		res1.push_back(mn + '0');
		--cnt[mn];
		break;
	}

	if (!mn)
	{
		printf("%s", t);
		for (int i = 0; i < cnt[0]; ++i)
			printf("0");
		return 0;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (i == t[0] - '0')
		{
			if (type == -1)
			{
				res1 += string(t);
				for (int j = 0; j < cnt[i]; ++j)
					res1.push_back(i + '0');
			}
			else
			{
				for (int j = 0; j < cnt[i]; ++j)
					res1.push_back(i + '0');
				res1 += string(t);
			}
		}
		else for (int j = 0; j < cnt[i]; ++j)
			res1.push_back(i + '0');
	}

	++cnt[mn];
	if (t[0] != '0')
	{
		res2 = string(t);
		for (int i = 0; i < 10; ++i)
		for (int j = 0; j < cnt[i]; ++j)
			res2.push_back(i + '0');
	}

	if (res2.empty() || res1 < res2)
		printf("%s", res1.c_str());
	else
		printf("%s", res2.c_str());
	return 0;
}