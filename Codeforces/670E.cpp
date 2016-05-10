#include <bits/stdc++.h>

using namespace std;

int n, m, p;
char brack[500010], dir[500010];
int close[500010], open[500010], lef[500010], rig[500010];

int main()
{
	scanf("%d %d %d %s %s", &n, &m, &p, brack, dir);
	--p;
	memset(close, -1, sizeof(close));
	memset(open, -1, sizeof(open));
	memset(lef, -1, sizeof(lef));
	memset(rig, -1, sizeof(rig));

	stack<int> st;

	for (int i = 0; i < n; ++i)
	if (brack[i] == '(')
		st.push(i);
	else
	{
		close[st.top()] = i;
		open[i] = st.top();
		st.pop();
	}

	for (int i = 1; i < n-1; ++i)
		lef[i] = i-1, rig[i] = i+1;
	lef[n-1] = n-2, rig[0] = 1;

	for (int i = 0; i < m; ++i)
	{
		if (dir[i] == 'R')
			p = rig[p];
		else if (dir[i] == 'L')
			p = lef[p];
		else
		{
			if (brack[p] == '(')
			{
				int pafter = rig[close[p]];
				if (pafter < 0)
					pafter = lef[p];
				if (lef[p] >= 0)
					rig[lef[p]] = rig[close[p]];
				if (rig[close[p]] >= 0)
					lef[rig[close[p]]] = lef[p];
				lef[p] = rig[p] = -2;
				rig[close[p]] = lef[close[p]] = -2;
				p = pafter;
			}
			else
			{
				int pafter = rig[p];
				if (pafter < 0)
					pafter = lef[open[p]];
				if (rig[p] >= 0)
					lef[rig[p]] = lef[open[p]];
				if (lef[open[p]] >= 0)
					rig[lef[open[p]]] = rig[p];
				lef[p] = rig[p] = -2;
				rig[open[p]] = lef[open[p]] = -2;
				p = pafter;
			}
		}
	}

	// for (int i = 0; i < n; ++i)
	// 	printf("%d: %d %d %d %d\n", i, lef[i], rig[i], open[i], close[i]);

	int i = 0;
	while (lef[i] != -1) ++i;

	while (i < n && rig[i] != -1)
	{
		printf("%c", brack[i]);
		i = rig[i];
	}
	printf("%c", brack[i]);
	return 0;
}