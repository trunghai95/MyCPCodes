#include <bits/stdc++.h>

using namespace std;

string s, t;

int main()
{
	cin >> s >> t;

	int n = s.length();

	++s[n-1];
	int i = n-1;
	while (1)
	{
		if (s[i] > 'z')
			s[i] = 'a', ++s[i-1];
		else
			break;

		if (--i == 0)
			break;
	}

	if (s[0] > 'z' || s >= t)
		cout << "No such string";
	else
		cout << s;
	return 0;
}