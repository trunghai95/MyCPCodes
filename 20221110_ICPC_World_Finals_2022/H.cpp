#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

#define pii pair<int,int>

using namespace std;

const int MAXN = 1000002;
const int MAXLEN = 10000002;

struct Info {
    int min;
    int sum;
    int id;
};

bool cmp(const Info &x, const Info &y) {
    return x.min > y.min;
}

bool cmpRev(const Info &x, const Info &y) {
    return x.min < y.min;
}

int n, sum;
char s[MAXLEN];
Info tmp;
vector<Info> pos, neg;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        tmp.min = tmp.sum = 0;
        tmp.id = i+1;
        for (int j = 0; s[j]; j++) {
            if (s[j] == '(') {
                tmp.sum++;
            } else {
                tmp.sum--;
            }
            if (tmp.sum < tmp.min) {
                tmp.min = tmp.sum;
            }
        }
        sum += tmp.sum;
        if (tmp.sum >= 0) {
            pos.push_back(tmp);
        } else {
            neg.push_back(tmp);
        }
        // printf("%d %s %d %d\n", i, s, x[i].min, x[i].sum);
    }
    if (sum != 0) {
        printf("impossible\n");
        return 0;
    }
    sum = 0;
    sort(pos.begin(), pos.end(), cmp);
    sort(neg.begin(), neg.end(), cmpRev);

    for (int i = 0; i < pos.size(); i++) {
        if (pos[i].min + sum < 0) {
            printf("impossible\n");
            return 0;
        }
        sum += pos[i].sum;
    }
    for (int i = 0; i < neg.size(); i++) {
        if (neg[i].min + sum < 0) {
            printf("impossible\n");
            return 0;
        }
        sum += neg[i].sum;
    }

    
    for (int i = 0; i < pos.size(); i++) {
        printf("%d\n", pos[i].id);
    }
    for (int i = 0; i < neg.size(); i++) {
        printf("%d\n", neg[i].id);
    }
    return 0;
}