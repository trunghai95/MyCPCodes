#include <bits/stdc++.h>

using namespace std;

int h1, h2, m1, m2, s1, s2, test;

int solve()
{
	if (h1 > h2)
		return -1;
	if (h2 > h1)
		return 1;

	if (m1 > m2)
		return -1;
	if (m2 > m1)
		return 1;

	if (s1 > s2)
		return -1;
	if (s2 > s1)
		return 1;

	return 0;
}

int main()
{
	cin >> test;

	while (test--)
	{
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

		int tmp = solve();
		if (tmp == 1)
			cout << "Player1\n";
		else if (tmp == -1)
			cout << "Player2\n";
		else
			cout << "Tie\n";
	}
	return 0;
}