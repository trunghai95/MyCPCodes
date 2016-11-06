#include <bits/stdc++.h>

using namespace std;

double r, v;
int test;

int main() {

	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt) {
		scanf("%lf %lf", &r, &v);
		printf("Case %d: %.8lf\n", tt, acos(-1)/2 * r / v);
	}
	return 0;
}