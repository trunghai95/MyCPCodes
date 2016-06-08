// 2D IT - O(n*m*log(n)*log(m))
// why slower than brute-force??? T_T

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

struct Node
{
	int maxx, sum;
	Node* child[4];

	Node() { maxx = sum = 0; memset(child, 0, sizeof(child)); }
};

struct Rec
{
	int top, lef, bot, rig;
	Rec() {}
	Rec(int t, int l, int b, int r): top(t), lef(l), bot(b), rig(r) {}
};

int n, m, a[1010][1010], q, nn, mm;
Node* root;

void build(Node* &node, Rec r)
{
	if (r.top > r.bot || r.lef > r.rig)
		return;

	node = new Node();
	if (r.top == r.bot && r.lef == r.rig)
	{
		node->maxx = node->sum = a[r.top][r.lef];
		return;
	}

	int mid1 = (r.top + r.bot) / 2;
	int mid2 = (r.lef + r.rig) / 2;
	build(node->child[0], Rec(r.top, r.lef, mid1, mid2));
	if (node->child[0])
	{
		node->maxx = max(node->maxx, node->child[0]->maxx);
		node->sum += node->child[0]->sum;
	}
	build(node->child[1], Rec(r.top, mid2+1, mid1, r.rig));
	if (node->child[1])
	{
		node->maxx = max(node->maxx, node->child[1]->maxx);
		node->sum += node->child[1]->sum;
	}
	build(node->child[2], Rec(mid1+1, r.lef, r.bot, mid2));
	if (node->child[2])
	{
		node->maxx = max(node->maxx, node->child[2]->maxx);
		node->sum += node->child[2]->sum;
	}
	build(node->child[3], Rec(mid1+1, mid2+1, r.bot, r.rig));
	if (node->child[3])
	{
		node->maxx = max(node->maxx, node->child[3]->maxx);
		node->sum += node->child[3]->sum;
	}
}

pii query(Node* node, Rec r, Rec g)
{
	if (node == NULL || r.top > r.bot || r.lef > r.rig)
		return pii(0,0);
	if (r.top > g.bot || r.bot < g.top || r.lef > g.rig || r.rig < g.lef)
		return pii(0,0);

	if (r.top >= g.top && r.bot <= g.bot && r.lef >= g.lef && r.rig <= g.rig)
		return pii(node->maxx, node->sum);

	pii res(0,0), tmp;
	int mid1 = (r.top + r.bot) / 2;
	int mid2 = (r.lef + r.rig) / 2;
	tmp = query(node->child[0], Rec(r.top, r.lef, mid1, mid2), g);
	res.F = max(res.F, tmp.F);
	res.S += tmp.S;
	tmp = query(node->child[1], Rec(r.top, mid2+1, mid1, r.rig), g);
	res.F = max(res.F, tmp.F);
	res.S += tmp.S;
	tmp = query(node->child[2], Rec(mid1+1, r.lef, r.bot, mid2), g);
	res.F = max(res.F, tmp.F);
	res.S += tmp.S;
	tmp = query(node->child[3], Rec(mid1+1, mid2+1, r.bot, r.rig), g);
	res.F = max(res.F, tmp.F);
	res.S += tmp.S;

	return res;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
		scanf("%d", a[i] + j);

	build(root, Rec(1, 1, n, m));

	scanf("%d", &q);

	while (q--)
	{
		scanf("%d %d", &nn, &mm);
		if (nn == 1 && mm == 1)
		{
			printf("0\n");
			continue;
		}
		int res = 2e9;

		for (int i = 1; i <= n - nn + 1; ++i)
		for (int j = 1; j <= m - mm + 1; ++j)
		{
			pii tmp = query(root, Rec(1,1,n,m), Rec(i,j,i+nn-1,j+mm-1));
			res = min(res, tmp.F*nn*mm - tmp.S);
		}

		printf("%d\n", res);
	}
	return 0;
}