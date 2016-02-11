//WA
#include <bits/stdc++.h>

using namespace std;

int n, R, r;
const double PI = 3.14159265;

int main()
{
	cin >> n >> R >> r;

	if (r > R)
	{
		cout << "NO";
		return 0;
	}

	if (r*2 > R)
	{
		if (n > 1)
			cout << "NO";
		else
			cout << "YES";
		return 0;
	}

	if (r*2 == R)
	{
		if (n <= 2)
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}

	double goc = asin(1.0*r/(R-r));
	//cout << goc << '\n';
	int num = floor(PI/goc);
	//cout << num << '\n';

	if (n <= num)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}