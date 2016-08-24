#include <bits/stdc++.h>

using namespace std;

const int MAX = 44721;

int a, b, c, d, cnt0 = 1, cnt1 = 1;
char res[1000010];

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);

	while (cnt0 <= MAX) {
		if (cnt0*(cnt0-1)/2 == a)
			break;
		++cnt0;
	}

	while (cnt1 <= MAX) {
		if (cnt1*(cnt1-1)/2 == d)
			break;
		++cnt1;
	}

	if (cnt0 > MAX || cnt1 > MAX) {
		printf("Impossible\n");
		return 0;
	}

	if (a == 0 && b == 0 && c == 0 && d == 0) {
		printf("0\n");
		return 0;
	}

	if (a == 0 && b == 0 && c == 0)
		cnt0 = 0;

	if (d == 0 && b == 0 && c == 0)
		cnt1 = 0;

	if (b+c != cnt0*cnt1) {
		printf("Impossible\n");
		return 0;
	}

	for (int i = 0; i < cnt0; ++i)
		res[i] = '0';
	for (int i = cnt0; i < cnt0+cnt1; ++i)
		res[i] = '1';

	int tmp = 0;
	int curpos = cnt0;

	while (tmp < c) {
		int r = min(cnt0, c - tmp);
		swap(res[curpos], res[curpos - r]);
		++curpos;
		tmp += r;
	}

	printf("%s\n", res);
	return 0;
}