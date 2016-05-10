#include <bits/stdc++.h>

using namespace std;

const int MAXT = 1439;

int a, ta, b, tb, h, m, ti, tca, tcb;

int main()
{
	scanf("%d %d %d %d %d:%d", &a, &ta, &b, &tb, &h, &m);
	ti = h*60 + m;
	tca = tcb = 300;
	int res = 0;

	while (tcb + tb <= ti)
		tcb += b;
	while (tcb < ti + ta && tcb <= MAXT)
		++res, tcb += b;

	printf("%d", res);
	return 0;
}