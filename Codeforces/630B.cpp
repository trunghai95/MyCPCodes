#include <bits/stdc++.h>

using namespace std;

typedef double ld;

const ld rate = 1.000000011;

int main()
{
	ld n, t;

	cin >> n >> t;
	printf("%.20lf", (double)n*pow(rate, t));
	return 0;
}