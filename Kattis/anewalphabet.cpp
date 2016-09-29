#include <bits/stdc++.h>

using namespace std;

char a;
string s[26] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", 
	"1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "\'][\'", "|_|", 
	"\\/", "\\/\\/", "}{", "`/", "2"};

int main() {
	while (scanf("%c", &a) != EOF) {
		if ((a >= 'a' && a <= 'z')) {
			printf("%s", s[a - 'a'].c_str());
		} else if (a >= 'A' && a <= 'Z') {
			printf("%s", s[a - 'A'].c_str());
		} else {
			printf("%c", a);
		}
	}
	printf("\n");
	return 0;
}