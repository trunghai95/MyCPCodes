#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;

int test, n;
bool ck[100010];

bool cw(const point &a, const point &b, const point &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

vector<int> convexHull(vector<point> &p) {
    int n = p.size();
    if (n <= 1)
    {
    	vector<int> q;
    	if (n == 1)
    		q.push_back(0);
        return q;
    }
    int k = 0;
    sort(p.begin(), p.end());
    vector<int> q(n * 2);
    for (int i = 0; i < n; q[k++] = i++)
        for (; k >= 2 && !cw(p[q[k - 2]], p[q[k - 1]], p[i]); --k);

    for (int i = n - 2, t = k; i >= 0; q[k++] = i--)
        for (; k > t && !cw(p[q[k - 2]], p[q[k - 1]], p[i]); --k);

    q.resize(k - 1 - (q[0] == q[1]));
    return q;
}

ll triangleArea(const point &a, const point &b, const point &c)
{
	ll res = abs(a.first*b.second + b.first*c.second + c.first*a.second
		- a.second*b.first - b.second*c.first - c.second*a.first);
	return res;
}

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d", &n);
		memset(ck, 0, n*sizeof(bool));

		vector<point> p;
		ll x, y;

		for (int i = 0; i < n; ++i)
		{
			scanf("%lld %lld", &x, &y);
			p.push_back(point(x, y));
		}

		vector<int> conv1 = convexHull(p);

		if (conv1.size() == p.size())
		{
			printf("-1\n");
			continue;
		}

		for (int i = 0; i < conv1.size(); ++i)
			ck[conv1[i]] = true;

		vector<point> inp;
		for (int i = 0; i < p.size(); ++i)
		{
			if (!ck[i])
				inp.push_back(p[i]);
		}

		vector<int> conv2 = convexHull(inp);

		ll mn = 2e18, area = p[conv1[0]].first * p[conv1.back()].second
						- p[conv1[0]].second * p[conv1.back()].first;

		for (int i = 1; i < conv1.size(); ++i)
			area += p[conv1[i]].first * p[conv1[i - 1]].second
					- p[conv1[i]].second * p[conv1[i - 1]].first;

		int ii = 0;
		int n1 = conv1.size();
		int n2 = conv2.size();
		// cout << n1 << "aaa" << n2 << ' ' << area << '\n';

		for (int i = 0; i < n1; ++i)
		{
			while (1)
			{
				ll s1 = triangleArea(p[conv1[i]], p[conv1[(i+1)%n1]],
					inp[conv2[ii]]);
				ll s2 = triangleArea(p[conv1[i]], p[conv1[(i+1)%n1]],
					inp[conv2[(ii+1)%n2]]);
				if (s1 > s2)
					ii = (ii+1)%n2;
				else
					break;
			}

			while (1)
			{
				ll s1 = triangleArea(p[conv1[i]], p[conv1[(i+1)%n1]],
					inp[conv2[ii]]);
				ll s2 = triangleArea(p[conv1[i]], p[conv1[(i+1)%n1]],
					inp[conv2[(ii-1+n2)%n2]]);
				if (s1 > s2)
					ii = (ii-1+n2)%n2;
				else
					break;
			}

			mn = min(mn, triangleArea(p[conv1[i]], p[conv1[(i+1)%n1]], inp[conv2[ii]]));
		}

		printf("%lld\n", area - mn);
	}
	return 0;
}