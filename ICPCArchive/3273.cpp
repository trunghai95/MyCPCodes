#include <bits/stdc++.h>

using namespace std;

const int START = 5*3600 + 37*60;
const int END = 18*3600 + 17*60;
const double EPS = 1e-12;
const double PI = acos(-1);

int n, w, h, m[111], d[111], start, endd, id;

void printHMS(int t) {
	int h = t/3600, m = (t/60)%60, s = t%60;
	printf("%02d:%02d:%02d", h, m, s);
}

int main() {
	int tt = 0;
	while (true) {
		scanf("%d", &n);

		if (!n) return 0;

		scanf("%d %d", &w, &h);
		for (int i = 1; i < n; ++i) {
			scanf("%d %d", m+i, d+i);
		}
		scanf("%d", m+n);

		printf("Apartment Complex: %d\n", ++tt);
		while (true) {
			scanf("%d", &id);
			if (id == 0) break;
			printf("Apartment %d: ", id);
			int i = id % 100;
			int j = id / 100;
			if (i <= 0 || i > n || j > m[i] || j <= 0) {
				printf("Does not exist\n");
				continue;
			}

			int height = h*(j-1);

			if (i == 1) {
				start = START;
			} else {
				double ang = 0;
				int dist = 0;
				for (int k = i-1; k >= 1; --k) {
					dist += d[k];
					if (h*m[k] >= height) {
						ang = max(ang, atan((1.0*h*m[k] - height) / dist));
					}
					dist += w;
				}

				start = START + (int)(ang / PI * (END - START) + EPS);
			}

			if (i == n) {
				endd = END;
			} else {
				double ang = 0;
				int dist = 0;
				for (int k = i+1; k <= n; ++k) {
					dist += d[k-1];
					if (h*m[k] >= height) {
						ang = max(ang, atan((1.0*h*m[k] - height) / dist));
					}
					dist += w;
				}

				endd = START + (int)((PI - ang) / PI * (END - START) + EPS);
			}

			printHMS(start);
			printf(" - ");
			printHMS(endd);
			printf("\n");
		}
	}
	return 0;
}