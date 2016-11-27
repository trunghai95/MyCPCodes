#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
vector<int> tn, tn2;
bool ck[MAXN+5];

void init() {
    for (int i = 1; ; ++i) {
        int tmp = i*(i+1)/2;
        if (tmp > MAXN) break;
        tn.push_back(tmp);
    }

    for (int i = 0; i < (int)tn.size(); ++i)
    for (int j = i; j < (int)tn.size(); ++j) {
        if (tn[i] + tn[j] <= MAXN)
            tn2.push_back(tn[i] + tn[j]);
        else
            break;
    }

    for (int i = 0; i < (int)tn.size(); ++i)
    for (int j = 0; j < (int)tn2.size(); ++j) {
        if (tn[i] + tn2[j] <= MAXN)
            ck[tn[i] + tn2[j]] = true;
    }
}

int test, n;

int main() {
    init();
    scanf("%d", &test);

    while (test --> 0) {
        scanf("%d", &n);

        if (ck[n])
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
