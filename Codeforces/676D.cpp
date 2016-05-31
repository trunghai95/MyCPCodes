#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

struct Node
{
	pii pos;
	int dist, rot;
	Node() {}
	Node(pii p, int d, int r): pos(p), dist(d), rot(r) {}
};

struct cmp
{
	bool operator()(Node x, Node y) { return x.dist > y.dist; }
};

int n, m;
char a[1010][1010];
bool visited[1010][1010][4];
pii src, dst;

bool valid(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m && a[x][y] != '*';
}

char cur[] = { '-', '|', '^', '>', '<', 'v', 'L', 'R', 'U', 'D'};
char nxt[] = { '|', '-', '>', 'v', '^', '<', 'U', 'D', 'R', 'L'};
char f1[] = "+->LUD", f2[] = "+-<UDR";

char nextchar(char c, int rot)
{
	if (c == '*' || c == '+')
		return c;
	rot = rot % 4;
	while (rot--)
	{
		int i;
		for (i = 0; i < 10; ++i)
		if (cur[i] == c)
			break;
		c = nxt[i];
	}
	return c;
}

int proc(char c, char cc, int s = 0)
{
	// cout << c << cc << ' ' << s << '\n';
	if (s == 4)
		return -1;
	bool b1 = false, b2 = false;
	for (int i = 0; i < 6 && !b1; ++i)
		b1 = (c == f1[i]);
	for (int i = 0; i < 6 && !b2; ++i)
		b2 = (cc == f2[i]);
	if (!b1 || !b2)
	{
		int tmp = proc(nextchar(c,1), nextchar(cc,1), s+1);
		if (tmp == -1)
			return -1;
		return tmp + 1;
	}
	else
		return 0;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%s", a[i]+1);

	scanf("%d %d %d %d", &src.F, &src.S, &dst.F, &dst.S);
	priority_queue<Node, vector<Node>, cmp> q;
	q.push(Node(src, 0, 0));

	while (!q.empty())
	{
		Node u = q.top(); q.pop();
		if (visited[u.pos.F][u.pos.S][u.rot])
			continue;
		// cout << u.pos.F << ' ' << u.pos.S << ' ' << u.rot << '\n';
		visited[u.pos.F][u.pos.S][u.rot] = true;
		if (u.pos == dst)
		{
			printf("%d", u.dist);
			return 0;
		}

		char cu = nextchar(a[u.pos.F][u.pos.S], u.rot);
		pii np = pii(u.pos.F + 1, u.pos.S);
		if (valid(np.F, np.S))
		{
			char cc = nextchar(a[np.F][np.S], u.rot);
			int tmp = proc(nextchar(cu,3), nextchar(cc,3));
			if (tmp != -1 && !visited[np.F][np.S][(u.rot + tmp) % 4])
				q.push(Node(np, u.dist + tmp + 1, (u.rot + tmp) % 4));
		}
		np = pii(u.pos.F - 1, u.pos.S);
		if (valid(np.F, np.S))
		{
			char cc = nextchar(a[np.F][np.S], u.rot);
			int tmp = proc(nextchar(cu,1), nextchar(cc,1));
			if (tmp != -1 && !visited[np.F][np.S][(u.rot + tmp) % 4])
				q.push(Node(np, u.dist + tmp + 1, (u.rot + tmp) % 4));
		}
		np = pii(u.pos.F, u.pos.S + 1);
		if (valid(np.F, np.S))
		{
			char cc = nextchar(a[np.F][np.S], u.rot);
			int tmp = proc(cu, cc);
			if (tmp != -1 && !visited[np.F][np.S][(u.rot + tmp) % 4])
				q.push(Node(np, u.dist + tmp + 1, (u.rot + tmp) % 4));
		}
		np = pii(u.pos.F, u.pos.S-1);
		if (valid(np.F, np.S))
		{
			char cc = nextchar(a[np.F][np.S], u.rot);
			int tmp = proc(nextchar(cu,2), nextchar(cc,2));
			if (tmp != -1 && !visited[np.F][np.S][(u.rot + tmp) % 4])
				q.push(Node(np, u.dist + tmp + 1, (u.rot + tmp) % 4));
		}
	}

	printf("-1");
	return 0;
}