#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 1000005;
int n;
vector<string> s;

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        char tmp[MAXN];
        scanf("%s\n", tmp);
        s.push_back(string(tmp));
        lens[tmp[0] - 'a'].push_back(strlen(tmp));
    }
    // for (int i = 0; i < n; i++) {
    //     cout << s[i] << endl;
    // }
    for (int i = 0; i < 26; i++) {
        sort(lens[i].begin(), lens[i].end());
    }
    for (int i = 0; i < n; i++) {
        vector<int>::iterator it = lower_bound(lens[s[i][0]-'a'].begin(), lens[s[i][0]-'a'].end(), s[i].size());
        while (true) {
            vector<int>::iterator nextIt = it;
            nextIt++;
            if (nextIt == lens[s[i][0]-'a'].end() || *nextIt > *it+1) {
                printf("%d ", int(*it) + 1 - int(s[i].size()));
                break;
            }
            it = nextIt;
        }
    }
    printf("\n");
    return 0;
}