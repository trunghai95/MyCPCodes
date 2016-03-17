#include <bits/stdc++.h>

using namespace std;

char s[10010], res[10010];
int len;

bool Try(int pos, int cnt4, int cnt7)
{
	if (pos == len)
	{
		res[pos] = 0;
		cout << res;
		return true;
	}

	if (s[pos] < '4' && cnt4)
	{
		// cout << "a\n";
		res[pos] = '4';
		res[pos+1] = 0;
		cout << res;
		for (int i = 1; i < cnt4; ++i)
			cout << 4;
		for (int i = 0; i < cnt7; ++i)
			cout << 7;
		return true;
	}

	if (s[pos] == '4' && cnt4)
	{
		// cout << "b\n";
		res[pos] = '4';
		if (Try(pos + 1, cnt4 - 1, cnt7))
			return true;
	}

	if (s[pos] < '7' && cnt7)
	{
		// cout << "c\n";
		res[pos] = '7';
		res[pos+1] = 0;
		cout << res;
		for (int i = 0; i < cnt4; ++i)
			cout << 4;
		for (int i = 1; i < cnt7; ++i)
			cout << 7;
		return true;
	}

	if (s[pos] == '7' && cnt7)
	{
		// cout << "d\n";
		res[pos] = '7';
		if (Try(pos + 1, cnt4, cnt7 - 1))
			return true;
	}

	return false;
}

int main()
{
	cin >> s;
	len = strlen(s);

	if (len&1 || s[0] < '4')
	{
		if (len&1) ++len;
		for (int i = 0; i < len/2; ++i)
			cout << '4';
		for (int i = 0; i < len/2; ++i)
			cout << '7';
		return 0;
	}

	if (!Try(0, len/2, len/2))
	{
		len += 2;
		for (int i = 0; i < len/2; ++i)
			cout << 4;
		for (int i = 0; i < len/2; ++i)
			cout << 7;
		return 0;
	}

	return 0;
}