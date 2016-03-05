#include <bits/stdc++.h>

using namespace std;

int n, s, cnt[5], res, tmp;

void print()
{
	for (int i = 1; i <= 4; ++i)
		printf("%d ", cnt[i]);
	printf("\n");
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &s), ++cnt[s];
// print();
	res = cnt[4];
	cnt[4] = 0;
// print();
	tmp = min(cnt[1], cnt[3]);
	res += tmp;
	cnt[1] -= tmp;
	cnt[3] -= tmp;
// print();
	tmp = min(cnt[1]/2, cnt[2]);
	res += tmp;
	cnt[1] -= tmp*2;
	cnt[2] -= tmp;
// print();
	res += cnt[2] / 2;
	cnt[2] %= 2;
// print();
	res += cnt[3] + cnt[1] / 4;
	cnt[3] = 0;
	cnt[1] %= 4;
// print();
	if (cnt[1] || cnt[2])
		++res;

	printf("%d", res);
	return 0;
}