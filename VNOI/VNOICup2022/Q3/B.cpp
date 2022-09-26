#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXN = 100003;
int n, q, left, right;
char s[MAXN], tmp1[MAXN], tmp2[MAXN];

void copySubstr(char* dst, char* src, int left, int right) {
    if (left < 0 || right < left) {
        dst[0] = 0;
        return;
    }
    strcpy(dst, src+left);
    dst[right-left+1] = 0;
}

int solve() {
    scanf("%d %d", &left, &right);
    left--;
    right--;
    copySubstr(tmp1, s, left, right);

    int cnt = 0;
    bool canContinue = true;
    while (canContinue && strlen(tmp1) > 0) {
        canContinue = false;
        // printf("%s\n", tmp1);
        for (int i = 0; tmp1[i+1] != 0; i++) {
            if (tmp1[i] == '(' && tmp1[i+1] == ')') {
                int l = i, r = i+1;
                while (l >= 0 && tmp1[l] == '(' && tmp1[r] == ')') {
                    l--;
                    r++;
                }
                copySubstr(tmp2, tmp1, 0, l-1);
                copySubstr(tmp2+l, tmp1, r+1, strlen(tmp1)-1);
                strcpy(tmp1, tmp2);
                ++cnt;
                canContinue = true;
                break;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d %s", &n, &q, s);
    while (q --> 0) {
        printf("%d\n", solve());
    }
    return 0;
}