#include <bits/stdc++.h>

using namespace std;

int w, L;
double dp[110][10];

int main() {

	while (scanf("%d %d", &w, &L) != EOF) {
		memset(dp, 0, sizeof(dp));

		double tmp = 100.0 / (w+1);

		for (int i = 0; i <= w; ++i)
			dp[1][i] = tmp;

		for (int i = 2; i <= L; ++i) {
			for (int j = 0; j <= w; ++j) {
				dp[i][j] = dp[i-1][j];
				if (j > 0)
					dp[i][j] += dp[i-1][j-1];
				if (j < w)
					dp[i][j] += dp[i-1][j+1];
				dp[i][j] *= tmp / 100.0;
			}
		}

		double res = 0;;
		for (int i = 0; i <= w; ++i)
			res += dp[L][i];

		printf("%.5lf\n", res);
	}
	return 0;
}