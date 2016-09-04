#include <bits/stdc++.h>

using namespace std;

int test, n, p, d;
double w[50], per[50];
char name[50][50];

int main() {
	scanf("%d", &test);

	for (int tt = 1; tt <= test ; ++tt) {
		scanf("%d %d %d", &n, &p, &d);
		int mn = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s %lf %lf", name[i], w+i, per+i);
			if (per[i] == 100.0)
				mn = i;
		}

		double scale = 1.0*d/p;
		w[mn] = w[mn] * scale;
		for (int i = 0; i < n; ++i)
		if (i != mn) {
			w[i] = w[mn] * per[i] / 100.0;
		}

		printf("Recipe # %d\n", tt);
		for (int i = 0; i < n; ++i)
			printf("%s %.1lf\n", name[i], w[i]);
		for (int i = 0; i < 40; ++i)
			printf("-");
		printf("\n");
	}
	return 0;
}