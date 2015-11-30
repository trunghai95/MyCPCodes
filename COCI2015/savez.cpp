#include <bits/stdc++.h>

using namespace std;

bool cmp(string x, string y)
{
    if (x.length() > y.length()) return false;

    return (x == string(y, 0, x.length()) && x == string(y, y.length() - x.length(), x.length()));
}

vector<string> s;
int n;

void find_lis(vector<string> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;

	if (a.empty()) return;

	b.push_back(0);

	for (size_t i = 1; i < a.size(); i++)
        {
                // If next element a[i] is greater than last element of
                // current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (cmp(a[b.back()], a[i]))
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}

                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a).
                // Size of b is always <=k and hence contributes O(log k) to complexity.
		for (u = 0, v = b.size()-1; u < v;)
                {
			int c = (u + v) / 2;
			if (cmp(a[b[c]], a[i])) u=c+1; else v=c;
		}

                // Update b if new value is smaller then previously referenced value
		if (cmp(a[i], a[b[u]]))
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}

	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    string tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        s.push_back(tmp);
    }

    vector<int> lis;
    find_lis(s, lis);
    cout << lis.size();
    return 0;
}
