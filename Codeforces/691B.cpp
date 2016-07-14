#include <bits/stdc++.h>

using namespace std;

char s[2000];

bool solve()
{
	int n = strlen(s);
	for (int i = 0; s[i]; ++i)
	{
		char x = s[i], y = s[n - i - 1];
		if ((x == 'A' && y == 'A')
			|| (x == 'b' && y == 'd')
			|| (x == 'd' && y == 'b')
			|| (x == 'H' && y == 'H')
			|| (x == 'I' && y == 'I')
			|| (x == 'M' && y == 'M')
			|| (x == 'O' && y == 'O')
			|| (x == 'o' && y == 'o')
			|| (x == 'p' && y == 'q')
			|| (x == 'q' && y == 'p')
			|| (x == 'T' && y == 'T')
			|| (x == 'U' && y == 'U')
			|| (x == 'V' && y == 'V')
			|| (x == 'v' && y == 'v')
			|| (x == 'W' && y == 'W')
			|| (x == 'w' && y == 'w')
			|| (x == 'X' && y == 'X')
			|| (x == 'x' && y == 'x')
			|| (x == 'Y' && y == 'Y'))
			{}
		else
			return false;
	}

	return true;
}

int main()
{
	scanf("%s", s);

	if (solve())
		cout << "TAK";
	else
		cout << "NIE";
	return 0;
}