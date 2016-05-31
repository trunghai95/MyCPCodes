#include <bits/stdc++.h>

using namespace std;

char s[200];
int cnt[300];

bool cmp(int x, int y) { return x > y; }

int main()
{
	scanf("%s", s);
	int n = strlen(s);

	for (int i = 0; i < n; ++i)
		++cnt[s[i]];

	sort(cnt, cnt+300, cmp);
	int res = 0;
	for (int i = 2; i < 50; ++i)
		res += cnt[i];
	printf("%d", res);
	return 0;
}