#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct cmp
{
	bool operator()(int x, int y) { return x > y; }
};

int width, height, n;
set<pii> vSeg, hSeg;
map<int,int, cmp> vLen, hLen;

int main()
{
	scanf("%d %d %d", &width, &height, &n);

	vSeg.insert(pii(width, 0));
	hSeg.insert(pii(height, 0));
	vLen[width] = 1;
	hLen[height] = 1;

	for (int i = 0; i < n; ++i)
	{
		char s[5];
		int x;
		scanf("%s %d", s, &x);
		if (s[0] == 'V')
		{
			set<pii>::iterator sit = vSeg.lower_bound(pii(x, -1));
			map<int,int,cmp>::iterator mit = vLen.find((*sit).first - (*sit).second);
			if ((*mit).second == 1)
				vLen.erase(mit);
			else
				--(*mit).second;
			++vLen[(*sit).first - x];
			++vLen[x - (*sit).second];
			vSeg.insert(pii((*sit).first, x));
			vSeg.insert(pii(x, (*sit).second));
			vSeg.erase(sit);
		}
		else
		{
			set<pii>::iterator sit = hSeg.lower_bound(pii(x, -1));
			map<int,int,cmp>::iterator mit = hLen.find((*sit).first - (*sit).second);
			if ((*mit).second == 1)
				hLen.erase(mit);
			else
				--(*mit).second;
			++hLen[(*sit).first - x];
			++hLen[x - (*sit).second];
			hSeg.insert(pii((*sit).first, x));
			hSeg.insert(pii(x, (*sit).second));
			hSeg.erase(sit);
		}

		printf("%lld\n", (ll)(*vLen.begin()).first * (*hLen.begin()).first);
	}
	return 0;
}