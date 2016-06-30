#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int test, c;
char s[10010];

int main()
{
	scanf("%d", &test);

	while (test--)
	{
		scanf("%d %s", &c, s);
		stack<pii> st;
		vector<char> res;
		st.push(pii(0, 0));
		int len = strlen(s);

		if (!c)
			res.push_back(s[0]);

		for (int i = 1; i < len; ++i)
		{
			if (s[i] == '(')
				continue;
			if (s[i] == ')')
			{
				st.pop();
				continue;
			}
			++st.top().second;
			if (s[i] == '.')
				continue;
			if (st.top().second == 1)
				st.push(pii(st.top().first - 1, 0));
			else
				st.push(pii(st.top().first + 1, 0));

			if (st.top().first == c)
				res.push_back(s[i]);
		}

		if (res.empty())
			printf("Common Gandhijee!\n");
		else
		{
			sort(res.begin(), res.end());
			for (int i = 0; i < (int)res.size(); ++i)
				printf("%c", res[i]);
			printf("\n");
		}
	}
	return 0;
}