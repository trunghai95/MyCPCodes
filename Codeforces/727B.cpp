#include <bits/stdc++.h>

using namespace std;

char s[1010];
int dollar, cent, i, j;

int main() {
	scanf("%s", s);

	for (i = 0; s[i] != 0; ++i) {

		if (s[i] >= '0' && s[i] <= '9') {
			string tmp;
			for (j = i; (s[j] >= '0' && s[j] <= '9') || s[j] == '.'; ++j) {
				tmp.push_back(s[j]);
			}

			int centTmp = 0, dollarTmp = 0;
				
			if (tmp.length() > 3 && tmp[tmp.length() - 3] == '.') {
				centTmp = tmp[tmp.length()-2]*10 + tmp[tmp.length()-1] - '0'*11;
				tmp.erase(tmp.length() - 3);
			}

			for (int i = 0; i < (int)tmp.length(); ++i)
			if (tmp[i] != '.') {
				dollarTmp = dollarTmp * 10 + tmp[i] - '0';
			}

			dollar += dollarTmp;
			cent += centTmp;
			i = j-1;
		}
	}

	dollar += cent/100;
	cent %= 100;

	if (dollar == 0) {
		printf("0.%02d\n", cent);
		return 0;
	}

	string tmp;
	while (dollar) {
		if (tmp.length() % 4 == 3)
			tmp.push_back('.');
		tmp.push_back(dollar % 10 + '0');
		dollar /= 10;
	}

	reverse(tmp.begin(), tmp.end());
	printf("%s", tmp.c_str());
	if (cent) {
		printf(".%02d", cent);
	}
	printf("\n");
	return 0;
}