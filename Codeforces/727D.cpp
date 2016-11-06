#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int total[7], n, res[100010];
string name[7] = {"", "S", "M", "L", "XL", "XXL", "XXXL"};
pii a[100010];
char ss[20];

int main() {
	for (int i = 1; i <= 6; ++i) {
		scanf("%d", total+i);
	}

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%s", ss);
		string s(ss);
		int comma = s.find(',');
		string t(s, 0, comma);
		for (int j = 0; j < 7; ++j) {
			if (t == name[j]) {
				a[i].F = j;
				break;
			}
		}

		if (comma != -1) {
			t = string(s, comma + 1);
			for (int j = 0; j < 7; ++j) {
				if (t == name[j]) {
					a[i].S = j;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= 6; ++i)
	for (int j = 1; j <= n; ++j)
	if (a[j].F == i && a[j].S == 0) {
		if (total[i] <= 0) {
			printf("NO\n");
			return 0;
		}
		--total[i];
		a[j].F = 0;
		res[j] = i;
	}

	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= n; ++j)
		if (a[j].S == i) {
			if (total[i] <= 0) {
				printf("NO\n");
				return 0;
			}
			a[j].F = a[j].S = 0;
			--total[i];
			res[j] = i;
		}

		for (int j = 1; total[i] > 0 && j <= n; ++j)
		if (a[j].F == i) {
			--total[i];
			a[j].F = a[j].S = 0;
			res[j] = i;
		}
	}

	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		printf("%s\n", name[res[i]].c_str());
	}
	return 0;
}