#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld PI = 3.14159265359;

ld d, h, v, e;

int main()
{
	cin >> d >> h >> v >> e;
	v = v/PI/d/d*4.0;
	v -= e;
	if (v <= 0)
		cout << "NO";
	else
	{
		v = h/v;
		cout << "YES\n" << setprecision(13) << v;
	}
	return 0;
}