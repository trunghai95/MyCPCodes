#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, char> pic;

#define F first
#define S second

int n, m;
pic tmp;
vector<pic> t, s, vc;
char str[100];
ll res = 0;
ll z[400010];

void read()
{
	scanf("%s", str);
	int len = strlen(str);
	tmp.S = str[len - 1];
	str[len - 2] = 0;
	sscanf(str, "%lld", &tmp.F);
}

void makez()
{
	int L = 0, R = 0, N = vc.size();
	for (int i = 1; i < N; ++i) {
	    if (i > R) {
	        L = R = i;
	        while (R < N && vc[R-L] == vc[R]) ++R;
	        z[i] = R-L; R--;
	    }
	    else {
	        int k = i-L;
	        if (z[k] < R-i+1) z[i] = z[k];
	        else {
	            L = i;
	            while (R < N && vc[R-L] == vc[R]) ++R;
	            z[i] = R-L; --R;
	        }
	    }
	}

}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		read();
		if (t.empty() || tmp.S != t.back().S)
			t.push_back(tmp);
		else
			t.back().F += tmp.F;
	}

	for (int i = 0; i < m; ++i)
	{
		read();
		if (s.empty() || tmp.S != s.back().S)
			s.push_back(tmp);
		else
			s.back().F += tmp.F;
	}

	if (s.size() == 1)
	{
		for (int i = 0; i < t.size(); ++i)
		if (t[i].S == s[0].S && t[i].F >= s[0].F)
			res += t[i].F - s[0].F + 1;
	}
	else if (s.size() == 2)
	{
		if (t.size() >= 2)
		{
			for (int i = 1; i < t.size(); ++i)
			if (t[i-1].S == s[0].S && t[i].S == s[1].S
				&& t[i-1].F >= s[0].F && t[i].F >= s[1].F)
				++res;
		}
	}
	else if (t.size() >= s.size())
	{
		for (int i = 1; i < s.size() - 1; ++i)
			vc.push_back(s[i]);

		for (int i = 0; i < t.size(); ++i)
			vc.push_back(t[i]);
		makez();

		for (int i = t.size() - s.size() + 1; i > 0; --i)
		{
			ll tmp = z[s.size() - 2 + i];
			if (tmp >= s.size() - 2 && s[0].S == t[i-1].S
				&& s[0].F <= t[i-1].F && s.back().S == t[i + s.size() - 2].S
				&& s.back().F <= t[i + s.size() - 2].F)
				++res;
		}
	}

	printf("%lld", res);
	return 0;
}