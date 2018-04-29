#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test, len;
char C[20], J[20], tmpC[20], tmpJ[20];
ll res, resC, resJ;

ll toLL(char *s)
{
	ll res = 0;
	for (int i = 0; i < len; ++i)
		res = res*10 + s[i] - '0';
	return res;
}

void Try(int p, int type)
{
	if (p == len)
	{
		ll tmpCl = toLL(tmpC), tmpJl = toLL(tmpJ);
		if (abs(tmpCl - tmpJl) < res)
		{
			res = abs(tmpCl - tmpJl);
			resC = tmpCl;
			resJ = tmpJl;
		}
		else if (abs(tmpCl - tmpJl) == res)
		{
			if (tmpCl < resC)
			{
				resC = tmpCl;
				resJ = tmpJl;
			}
			else if (tmpCl == resC)
			{
				if (tmpJl < resJ)
					resJ = tmpJl;
			}
		}
		return;
	}

	if (C[p] != '?' && C[p] == J[p])
	{
		tmpC[p] = C[p], tmpJ[p] = J[p];
		Try(p+1, type);
		return;
	}

	if (type == 1)
	{
		if (C[p] == '?')
			tmpC[p] = '0';
		else tmpC[p] = C[p];
		if (J[p] == '?')
			tmpJ[p] = '9';
		else tmpJ[p] = J[p];
		Try(p+1, type);
	}
	else if (type == 2)
	{
		if (C[p] == '?')
			tmpC[p] = '9';
		else tmpC[p] = C[p];
		if (J[p] == '?')
			tmpJ[p] = '0';
		else tmpJ[p] = J[p];
		Try(p+1, type);
	}
	else
	{
		if (C[p] != '?' && J[p] != '?')
		{
			tmpC[p] = C[p];
			tmpJ[p] = J[p];
			if (C[p] > J[p])
				Try(p+1, 1);
			else if (C[p] < J[p])
				Try(p+1, 2);
			else
				Try(p+1, 0);
		}
		else if (C[p] != '?')
		{
			tmpC[p] = tmpJ[p] = C[p];
			Try(p+1, type);
			if (C[p] != '0')
			{
				tmpJ[p] = C[p] - 1;
				Try(p+1, 1);
			}
			if (C[p] != '9')
			{
				tmpJ[p] = C[p] + 1;
				Try(p+1, 2);
			}
		}
		else if (J[p] != '?')
		{
			tmpC[p] = tmpJ[p] = J[p];
			Try(p+1, type);
			if (J[p] != '0')
			{
				tmpC[p] = J[p] - 1;
				Try(p+1, 2);
			}
			if (J[p] != '9')
			{
				tmpC[p] = J[p] + 1;
				Try(p+1, 1);
			}
		}
		else // ? ?
		{
			tmpC[p] = tmpJ[p] = '0';
			Try(p+1, 0);
			tmpC[p] = '1';
			Try(p+1, 1);
			tmpC[p] = '0', tmpJ[p] = '1';
			Try(p+1, 2);
		}
	}
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%s %s", C, J);
		len = strlen(C);
		
		res = 2e18;
		Try(0, 0);

		printf("Case #%d: %0*lld %0*lld\n", tt, len, resC, len, resJ);
	}
	return 0;
}