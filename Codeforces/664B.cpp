#include <bits/stdc++.h>

using namespace std;

char s[20];
int cntPos, cntNeg, n;
vector<bool> isPos;

int main()
{
	scanf("%s", s);
	cntPos = 1;

	while (1)
	{
		scanf("%s", s);
		if (s[0] == '=')
		{
			scanf("%d", &n);
			break;
		}
		if (s[0] == '+')
			++cntPos, isPos.push_back(true);
		else
			++cntNeg, isPos.push_back(false);
		scanf("%s", s);
	}

	int minPos = cntPos, maxPos = cntPos * n, minNeg = cntNeg, maxNeg = cntNeg * n;
	int resPos = -1, resNeg = -1;
	for (resPos = minPos; resPos <= maxPos; ++resPos)
	{
		int tmp = resPos - n;
		if (tmp >= minNeg && tmp <= maxNeg)
		{
			resNeg = tmp;
			break;
		}
	}

	if (resNeg == -1)
	{
		printf("Impossible");
		return 0;
	}
	// printf("%d %d\n", resPos, resNeg);

	vector<int> ps, ng;
	while ((int)ps.size() < cntPos)
	{
		if (resPos - n >= cntPos - (int)ps.size() - 1)
			ps.push_back(n);
		else
			ps.push_back(resPos - cntPos + (int)ps.size() + 1);
		resPos -= ps.back();
	}
	while ((int)ng.size() < cntNeg)
	{
		if (resNeg - n >= cntNeg - (int)ng.size() - 1)
			ng.push_back(n);
		else
			ng.push_back(resNeg - cntNeg + (int)ng.size() + 1);
		resNeg -= ng.back();
	}

	printf("Possible\n%d", ps.back());
	ps.pop_back();
	for (int i = 0; i < (int)isPos.size(); ++i)
	{
		if (isPos[i])
		{
			printf(" + %d", ps.back());
			ps.pop_back();
		}
		else
		{
			printf(" - %d", ng.back());
			ng.pop_back();
		}
	}
	printf(" = %d", n);
	return 0;
}