#include <bits/stdc++.h>

using namespace std;

string name[52];
int n, k;
bool f[52], ck[52];
char s[52];
int res[52];
vector<int> yeses;

int main() {
    for (int i = 0; i <= 50; ++i) {
        name[i].push_back('A' + (i % 26));
        if (i >= 26) {
            name[i].push_back('z');
        }
    }

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n-k+1; ++i) {
        scanf("%s", s);
        if (s[0] == 'Y') {
            memset(ck, 0, sizeof(ck));

            for (int j = 0; j < k; ++j) {
                ck[res[i+j]] = true;
            }

            int cur = 1;
            for (int j = 0; j < k; ++j)
            if (res[i+j] == 0) {
                while (ck[cur]) ++cur;
                res[i+j] = cur;
                ++cur;
            }

        } else {
            if (res[i] == 0) {
                res[i] = i;
            }

            if (i+k-1 <= n) {
                res[i+k-1] = res[i];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        printf("%s ", name[res[i]].c_str());
    }
    printf("\n");
    return 0;
}
