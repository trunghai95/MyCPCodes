#include <bits/stdc++.h>

using namespace std;

int h, m, a;
char s[10];

int main()
{
	scanf("%s %d", s, &a);

	h = s[0]*10 + s[1] - 11*'0';
	m = s[3]*10 + s[4] - 11*'0';
	// printf("%d %d %d\n", h, m, a);

	m += a;

	h += m / 60;
	h %= 24;

	m %= 60;

	printf("%02d:%02d", h, m);
	return 0;
}