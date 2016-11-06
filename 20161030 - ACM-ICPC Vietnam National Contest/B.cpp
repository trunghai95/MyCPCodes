#include <iostream>
#include <bits/stdc++.h>

#define fi(a,b,c) for(int a=b; a<=c; a++)
using namespace std;

typedef long long ll;

ll a[] {1,2,3,4,5,6,7,8,9,10,21,89,};

int cal(ll x) {
    int l = 0 ;

     int r = sizeof(a) / sizeof(ll);
     while (l <= r) {

        int mid = (l + r) >> 1;
        if (a[mid] <= x) {
            ans = mid ;
            l = mid+ 1;
        } else r = mid - 1;
     }
     return ans + 1;
}

int main()
{
    int tcase;
    scanf("%d", &tcase);
    sort(a, a + sizeof(a) / sizeof(ll));
    while (tcase --) {

        ll A, B;
        scanf("%lld %lld", &A, &B);
        printf("%d\n", cal(B) - cal(A-1));
    }
}
