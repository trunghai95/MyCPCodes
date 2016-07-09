#include <bits/stdc++.h>

using namespace std;

int n;
char s[50];
int nxt[4][10] = {{8,-1,-1,-1,1,2,3,4,5,6},
				   {-1,4,5,6,7,8,9,-1,0,-1},
				   {-1,2,3,-1,5,6,-1,8,9,-1},
				   {-1,-1,1,2,-1,4,5,-1,7,8}};

int main()
{
	scanf("%d %s", &n, s);
	for (int i = 0; i < 4; ++i)
	{
		bool f = true;
		for (int j = 0; f && j < n; ++j)
		{
			if (nxt[i][s[j] - '0'] == -1)
				f = false;
		}

		if (f)
		{
			printf("NO");
			return 0;
		}
	}

	printf("YES");
	return 0;
}