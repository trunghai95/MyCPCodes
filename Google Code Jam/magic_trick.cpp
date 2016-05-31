#include <bits/stdc++.h>

using namespace std;

int test, a, x;
bool ck1[20], ck2[20];

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		memset(ck1, 0, sizeof(ck1));
		memset(ck2, 0, sizeof(ck2));
		scanf("%d", &a);

		for (int i = 1; i <= 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				scanf("%d", &x);
				if (i == a)
					ck1[x] = true;
			}
		}

		scanf("%d", &a);

		for (int i = 1; i <= 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				scanf("%d", &x);
				if (i == a)
					ck2[x] = true;
			}
		}

		int res = -1;
		for (int i = 1; i <= 16; ++i)
		if (ck1[i] && ck2[i])
		{
			if (res == -1)
				res = i;
			else
				res = 1000;
		}

		printf("Case #%d: ", tt);

		if (res == -1)
			printf("Volunteer cheated!\n");
		else if (res == 1000)
			printf("Bad magician!\n");
		else
			printf("%d\n", res);
	}
	return 0;
}