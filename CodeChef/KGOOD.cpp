#include <bits/stdc++.h>
 
using namespace std;
 
int test, k, n, cnt[300];
char s[100010];
 
int proc(int lef, int rig)
{
	int res = 0;
	for (int i = 'a'; i <= 'z'; ++i)
	{
		if (cnt[i] < lef)
			res += cnt[i];
		if (cnt[i] > rig)
			res += cnt[i] - rig;
	}
 
	return res;
}
 
int main()
{
	scanf("%d", &test);
 
	while (test--)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%s %d", s, &k);
		n = strlen(s);
		int mx = 0;
		for (int i = 0; i < n; ++i)
			mx = max(mx, ++cnt[s[i]]);
 
		int res = 2e9;
		for (int i = 0; i <= mx; ++i)
			res = min(res, proc(i, i+k));
		printf("%d\n", res);
	}
	return 0;
} 