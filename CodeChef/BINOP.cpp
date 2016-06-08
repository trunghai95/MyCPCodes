#include <bits/stdc++.h>

using namespace std;

int test, cnt[2][2], len, res;
char a[1000010], b[1000010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%s %s", a, b);
		len = strlen(a);
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < len; ++i)
			++cnt[a[i] - '0'][b[i] - '0'];
		res = min(cnt[0][1], cnt[1][0]);
		cnt[0][1] -= res;
		cnt[1][0] -= res;
		cnt[0][0] += res;
		cnt[1][1] += res;

		if ((cnt[0][1] && !cnt[1][1]) || (cnt[1][0] && !cnt[0][0]))
			res = -1;
		else
			res += cnt[0][1] + cnt[1][0];

		if (res == -1)
			printf("Unlucky Chef\n");
		else
			printf("Lucky Chef\n%d\n", res);
	}
	return 0;
}