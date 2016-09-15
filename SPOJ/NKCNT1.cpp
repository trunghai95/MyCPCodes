#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug1(a) cout << #a << ": " << a << '\n'
#define debug2(a, b) cout << #a << ": " << a << " - " << #b << ": " << b << '\n'

const int MAXN = 5001;
int n, m, cntsq[MAXN][MAXN], cntx[MAXN][MAXN], cnty[MAXN][MAXN];
char s[MAXN][MAXN];
ll res;

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i]+1);
	}

	for (int i = n; i > 0; --i)
	for (int j = m; j > 0; --j)
	if (s[i][j] == '0') {
		cntx[i][j] = cntx[i+1][j] + 1;
		cnty[i][j] = cnty[i][j+1] + 1;
		int tmp = cntsq[i+1][j+1] + 1;
		tmp = min(tmp, min(cntx[i][j], cnty[i][j]));
		res += tmp;
		cntsq[i][j] = tmp;
	}

	printf("%lld\n", res);
	return 0;
}