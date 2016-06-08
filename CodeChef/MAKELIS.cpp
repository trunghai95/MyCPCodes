// by Nguyen Hoang Phuong

#include <bits/stdc++.h>

using namespace std;
 
const int MAX = 200;
int test, k, s[MAX], cntS, t[MAX], cntT, loss, run, bit[20], cntBit;
 
int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);
    while (test--){
        scanf("%d", &k);
        cntBit = 0;
        while (k > 1){
            bit[cntBit++] = ((k & 1) ? 1 : 0);
            k >>= 1;
        }
        reverse(bit, bit + cntBit);
 
        cntS = cntT = 0;
        loss = run = 1;
        for (int i = 0; i < cntBit; ++i){
            s[cntS++] = run + 2;
            s[cntS++] = run + 1;
            run += 2;
            if (bit[i] == 1){
                for (int j = 0; j < loss; ++j)
                    t[cntT++] = ++run;
                loss = 1;
            }
            else
                ++loss;
        }
 
        printf("%d\n1", 1 + cntS + cntT);
        for (int i = 0; i < cntT; ++i)
            printf(" %d", t[i]);
        printf("\n");
        for (int i = 0; i < cntS; ++i)
            printf("%d ", s[i]);
        printf("\n");
    }
    return 0;
}