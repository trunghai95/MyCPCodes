#include <bits/stdc++.h>

#define fi(a,b,c) for(int a=b; a<=c; a++)
#define pb push_back

typedef long long ll;


using namespace std;

const int MAX = 4005;
const long long MOD = (long long)(1e9) + 7ll;

char s[MAX + 10], t[MAX + 10] ;

vector <pair <ll, ll > > v;
int n, m;
const int BASE = 311317;
const int BASE2 = 24311;
long long Pow[40], Pow2[40];

int cnt[30];

int main()
{
  //  freopen("in.txt", "r", stdin);
    Pow[0] = 1;
    Pow2[0] = 1; 
     for (int i = 1; i <= 26; ++i)
        {
            Pow[i] = (Pow[i - 1] * BASE) % MOD;
            Pow2[i] = (Pow2[i-1] * BASE2) % MOD; 
        }

    scanf("%s %s", s, t);
    n = strlen(s);
    m = strlen(t);

    int ans = 0;
    fi(len, 0 ,min(n, m))
    {
        pair <ll, ll> my_hash = make_pair(0, 0);
        fi(i, 0, len-1) my_hash = make_pair((my_hash.first + Pow[s[i] - 'a']) % MOD,
                                (my_hash.second + Pow2[s[i] - 'a']) % MOD ); 

        fi(i, len-1, n- 1)
        {
            v.pb(my_hash);
           my_hash = make_pair((my_hash.first - Pow[s[i-len+1] - 'a'] + MOD) % MOD,
                                (my_hash.second - Pow2[s[i-len+1] - 'a'] + MOD) % MOD ); 
            if (i == n-1) continue;
            my_hash = make_pair((my_hash.first + Pow[s[i + 1] - 'a']) % MOD,
                                (my_hash.second + Pow2[s[i+1] - 'a']) % MOD ); 
        }

        my_hash = make_pair(0,0);

        sort(v.begin(), v.end());
        //for (int i = 0 ; i < v.size() ; i++) cout << v[i].first <<' '<< v[i].second <<endl; 
        fi(i, 0, len-1) my_hash = make_pair((my_hash.first + Pow[t[i] - 'a']) % MOD,
                                (my_hash.second + Pow2[t[i] - 'a']) % MOD ); 
       

        //cout <<endl; 

        fi(i, len-1, m- 1)
        {
            //cout <<my_hash.first <<' '<< my_hash.second <<endl; 
            vector <pair <ll , ll> > ::iterator it ;
            it = lower_bound(v.begin(), v.end(), my_hash);
            if (it != v.end() && *it == my_hash)
            {
                ans = len ;
                break;
            }
            my_hash = make_pair((my_hash.first - Pow[t[i-len+1] - 'a'] + MOD) % MOD,
                                (my_hash.second - Pow2[t[i-len+1] - 'a'] + MOD) % MOD ); 
            if (i == m-1) continue;
            my_hash = make_pair((my_hash.first + Pow[t[i + 1] - 'a']) % MOD,
                                (my_hash.second + Pow2[t[i+1] - 'a']) % MOD ); 
        }

        v.clear();

    }

    printf("%d", ans);
}
