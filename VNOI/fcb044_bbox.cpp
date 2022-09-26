#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int n;
char s[MAXN], res[MAXN];

int main() {
    scanf("%d\n%s", &n, s);
    
    int carry = 0;
    int sumbit = 0;
    for (int i = n-1; i >= 0; i--) {
        int sum = sumbit + carry;
        if (s[i]-'0' == (sum&1)) {
            res[i] = '0';
        } else {
            res[i] = '1';
        }
        sumbit += res[i] - '0';
        carry = ((carry + sumbit) >> 1);
        // printf("%d %d\n", sumbit, carry);
    }
    printf("%s\n", res);
    return 0;
}