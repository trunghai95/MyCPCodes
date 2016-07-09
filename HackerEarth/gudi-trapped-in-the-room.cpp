#include <bits/stdc++.h>

using namespace std;

int test, n, a, h;
string s;
bool ck[1000000];

int toInt(string &str)
{
	int res = 0, sz = str.length();
	for (int i = 0; i < sz; ++i)
		res = res*10 + str[i] - '0';
	return res;
}

string rotate(string &str)
{
	string res;
	int sz = str.length();
	for (int i = sz - h; i < sz; ++i)
		res.push_back(str[i]);
	for (int i = 0; i < sz - h; ++i)
		res.push_back(str[i]);
	return res;
}

string inc(string str)
{
	int sz = str.length();
	for (int i = 1; i < sz; i += 2)
		str[i] = (str[i] - '0' + a) % 10 + '0';
	return str;
}

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> test;

	while (test--)
	{
		cin >> s >> a >> h;
		n = s.length();
		h = h % n;
		memset(ck, 0, sizeof(ck));
		queue<string> q;
		int tmp = toInt(s);
		q.push(s);
		ck[tmp] = true;

		while (!q.empty())
		{
			string u = q.front();
			q.pop();
			string stmp = rotate(u);
			tmp = toInt(stmp);
			if (!ck[tmp])
			{
				ck[tmp] = true;
				q.push(stmp);
			}

			stmp = inc(u);
			tmp = toInt(stmp);
			if (!ck[tmp])
			{
				ck[tmp] = true;
				q.push(stmp);
			}
		}

		for (int i = 0; i < 1000000; ++i)
		if (ck[i])
		{
			printf("%0*d\n", n, i);
			break;
		}
	}
	return 0;
}