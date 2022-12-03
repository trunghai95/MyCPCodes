#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(const int &a, const int &b) const {
        return a > b;
    }
};

int q, x;
multiset<int> s1;
multiset<int, cmp> s2;
char s[10];

int main() {
    scanf("%d", &q);
    while (q --> 0) {
        scanf("%s", s);
        if (s[0] == 'M') {
            if (s1.size() == s2.size()) {
                int sum = *s1.begin() + *s2.begin();
                printf("%d%s\n", sum/2, (sum%2==0)?"":".5");
            } else {
                printf("%d\n", *s1.begin());
            }
        } else {
            scanf("%d", &x);
            if (s[0] == 'I') {
                // printf("in %d\n", x);
                if (x >= *s1.begin()) {
                    s1.insert(x);
                    if (s1.size() > s2.size() + 1) {
                        s2.insert(*s1.begin());
                        s1.erase(s1.begin());
                    }
                } else {
                    s2.insert(x);
                    if (s1.size() < s2.size()) {
                        s1.insert(*s2.begin());
                        s2.erase(s2.begin());
                    }
                }
            } else {
                // printf("out %d\n", x);
                if (x >= *s1.begin()) {
                    s1.erase(s1.find(x));
                    if (s1.size() < s2.size()) {
                        s1.insert(*s2.begin());
                        s2.erase(s2.begin());
                    }
                } else {
                    s2.erase(s2.find(x));
                    if (s1.size() > s2.size() + 1) {
                        s2.insert(*s1.begin());
                        s1.erase(s1.begin());
                    }
                }
            }
            // printf("%d %d %d %d\n", s1.size(), s2.size(), s1.empty()?-1:*s1.begin(), s2.empty()?-1:*s2.begin());
        }
    }
    return 0;
}