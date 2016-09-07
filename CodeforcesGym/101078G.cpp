#include <bits/stdc++.h>

using namespace std;

int test, n, ball[8], pt[2], a[1010];
int redTurn, playTurn;

int maxPoint(int last) {
	int res = ball[1] * 8;

	if (last == 1)
		res += 7;

	for (int i = 2; i <= 7; ++i)
	if (ball[i])
		res += i;

	return res;
}

int main() {
	scanf("%d", &test);

	while (test --> 0) {
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i)
			scanf("%d", a+i);

		playTurn = pt[0] = pt[1] = 0;
		redTurn = 1;
		ball[1] = 15;
		for (int i = 2; i <= 7; ++i)
			ball[i] = 1;

		int res = n;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 0) {
				playTurn = 1 - playTurn;
				if (pt[0] + maxPoint(0) < pt[1] || pt[1] + maxPoint(0) < pt[0]) {
					res = i;
					break;
				}
				continue;
			}

			pt[playTurn] += a[i];
			if (a[i] == 1)
				--ball[1];
			else if (a[i-1] != 1)
				--ball[a[i]];

			if (pt[playTurn] + maxPoint(a[i]) < pt[1 - playTurn] 
				|| pt[1 - playTurn] + maxPoint(0) < pt[playTurn]) {
				res = i;
				break;
			}
		}

		printf("%d\n", res);
	}
	return 0;
}