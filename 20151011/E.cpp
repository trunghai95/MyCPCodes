#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int NEO = 3;
const int MAX = 70;
int len, val, minVal, maxVal;
ll k, f[MAX + 1][NEO * 2 + 1][NEO * 2 + 1], g[MAX + 1], sum;
char res[MAX + 2];

int main(){
	ios_base::sync_with_stdio(0);

	f[0][0 + NEO][0 + NEO] = 1;
	for (int i = 0; i < MAX; ++i)
	for (int j = -3; j <= 3; ++j)
	for (int k = j; k <= 3; ++k)
	if (f[i][j + NEO][k + NEO]){
		if (k + 1 <= 3)
			f[i + 1][min(j + 1, 1) + NEO][max(k + 1, 1) + NEO] += f[i][j + NEO][k + NEO];
		if (j - 1 >= -3)
			f[i + 1][min(j - 1, -1) + NEO][max(k - 1, -1) + NEO] += f[i][j + NEO][k + NEO];
	}

	for (int i = 0; i <= MAX; ++i)
	for (int j = -3; j <= 3; ++j)
	for (int k = j; k <= 3; ++k)
		g[i] += f[i][j + NEO][k + NEO];

	cin >> k;

	len = 1;
	while (sum + g[len] < k){
		sum += g[len];
		++len;
	}

	k -= sum;
	for (int i = len, pos = 1; i >= 1; --i, ++pos){
		res[pos] = 'o';
		val = 0;
		minVal = 1e9;
		maxVal = -1e9;
		for (int t = pos; t >= 1; --t){
			val += (res[t] == 'o' ? 1 : -1);
			minVal = min(minVal, val);
			maxVal = max(maxVal, val);
		}

		if (minVal < -3 || maxVal > 3){
			res[pos] = 'z';
			continue;
		}

		sum = g[i - 1];
		for (int ii = -3; ii <= 3; ++ii)
		for (int jj = ii; jj <= 3; ++jj)
		if (minVal + ii < -3 || maxVal + jj > 3)
			sum -= f[i - 1][ii + NEO][jj + NEO];

		if (k <= sum)
			continue;
		res[pos] = 'z';
		k -= sum;
	}
	printf("%s", res + 1);

	return 0;
}