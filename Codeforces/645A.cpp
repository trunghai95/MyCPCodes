#include <bits/stdc++.h>

using namespace std;

char a[5][5], b[5][5], tmp1, tmp2;

int main()
{
	cin >> a[0] >> a[1] >> b[0] >> b[1];

	if (a[0][0] == 'A')
	{
		if (a[0][1] == 'X')
			tmp1 = a[1][1];
		else
			tmp1 = a[0][1];
	}
	else if (a[0][1] == 'A')
	{
		if (a[1][1] == 'X')
			tmp1 = a[1][0];
		else
			tmp1 = a[1][1];
	}
	else if (a[1][1] == 'A')
	{
		if (a[1][0] == 'X')
			tmp1 = a[0][0];
		else
			tmp1 = a[1][0];
	}
	else
	{
		if (a[0][0] == 'X')
			tmp1 = a[0][1];
		else
			tmp1 = a[0][0];
	}

	if (b[0][0] == 'A')
	{
		if (b[0][1] == 'X')
			tmp2 = b[1][1];
		else
			tmp2 = b[0][1];
	}
	else if (b[0][1] == 'A')
	{
		if (b[1][1] == 'X')
			tmp2 = b[1][0];
		else
			tmp2 = b[1][1];
	}
	else if (b[1][1] == 'A')
	{
		if (b[1][0] == 'X')
			tmp2 = b[0][0];
		else
			tmp2 = b[1][0];
	}
	else
	{
		if (b[0][0] == 'X')
			tmp2 = b[0][1];
		else
			tmp2 = b[0][0];
	}

	if (tmp1 == tmp2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}