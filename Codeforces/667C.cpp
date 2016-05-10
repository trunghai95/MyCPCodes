#include <bits/stdc++.h>

using namespace std;

string s;
set<string> res;
bool tried[10010][5];

void Try(string str, string last)
{
	if (tried[str.length()][last.length()])
		return;

	tried[str.length()][last.length()] = true;

	if (str.length() < 7)
		return;

	string tmp;
	if ((tmp = string(str.end() - 2, str.end())) != last)
	{
		res.insert(tmp);
		Try(string(str.begin(), str.end() - 2), tmp);
	}

	if (str.length() == 7)
		return;

	if ((tmp = string(str.end() - 3, str.end())) != last)
	{
		res.insert(tmp);
		Try(string(str.begin(), str.end() - 3), tmp);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> s;
	Try(s, string());

	cout << res.size() << '\n';
	for (set<string>::iterator it = res.begin(); it != res.end(); ++it)
	{
		cout << (*it) << '\n';
	}
	return 0;
}