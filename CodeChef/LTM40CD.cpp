// trau bo...

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int, pii> piii;
#define F first
#define S second

const int MAXA = 801;
const int MAX = 1600;
const double EPS = 1e-8;

double Try(double a, double b, double c) {
	double p = (a + b + c) / 2;
	double s = p*(p-a)*(p-b)*(p-c);
	return s / p / p;
}

double r;
vector<piii> res;

int main() {
	scanf("%lf", &r);

	r *= r;

	for (int a = 1; a <= MAXA; ++a)
	for (int b = a; b <= MAX; ++b) {
		int mx = min(a+b, MAX);

		for (int c = b; c <= mx; ++c) {
			if (abs(Try(a, b, c) - r) < EPS) {
				res.push_back(piii(a, pii(b, c)));
			}
		}
	}

	printf("%d\n", (int)res.size());
	for (int i = 0; i < (int)res.size(); ++i) {
		printf("%d %d %d\n", res[i].F, res[i].S.F, res[i].S.S);
	}
	return 0;
}