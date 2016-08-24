#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int n, res;
pii p[200010];

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i].F);

	for (int i = n; i < n*2; ++i)
		scanf("%d", &p[i].F), p[i].S = 1;

	sort(p, p+n+n);

	n *= 2;

	for (int i = 1; i < n; ++i)
	if (p[i].S != p[i-1].S) {
		++res;
		++i;
	}

	printf("%d\n", res);
	return 0;
}