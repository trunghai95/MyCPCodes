#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int r, g, b;

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
	{
		r += (s[i] == 'R');
		g += (s[i] == 'G');
		b += (s[i] == 'B');
	}

	if (r && !g && !b)
		cout << "R";
	else if (!r && g && !b)
		cout << "G";
	else if (!r && !g && b)
		cout << "B";
	else if (!r && g && b)
	{
		if (b == 1 && g == 1)
			cout << "R";
		else if (b == 1)
			cout << "BR";
		else if (g == 1)
			cout << "GR";
		else
			cout << "BGR";
	}
	else if (r && !g && b)
	{
		if (b == 1 && r == 1)
			cout << "G";
		else if (b == 1)
			cout << "BG";
		else if (r == 1)
			cout << "GR";
		else
			cout << "BGR";
	}
	else if (r && g && !b)
	{
		if (r == 1 && g == 1)
			cout << "B";
		else if (r == 1)
			cout << "BR";
		else if (g == 1)
			cout << "BG";
		else
			cout << "BGR";
	}
	else
		cout << "BGR";
	return 0;
}