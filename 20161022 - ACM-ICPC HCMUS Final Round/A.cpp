#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6;
int n, C, a[MAX], mx;
ll need, res;

struct Node{
	int h, cnt;
	Node *prev, *next;
	Node(const int& h) : h(h), cnt(1), prev(NULL), next(NULL) {}
};
Node *head = NULL, *tail = NULL, *node;

struct comp{
	bool operator () (Node *const & x, Node *const & y){
		return x->cnt > y->cnt;
	}
};

priority_queue <Node *, vector <Node *>, comp> heap;

int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &C);
	for (int i = 0; i < n; ++i){
		scanf("%d", a + i);
		if (i == 0 || a[i] > a[mx])
			mx = i;
	}

	for (int i = 0; i < n; ++i){
		if ((need += a[mx] - a[i]) > C)
			break;
		int j = (i + 1) % n;
		res += abs(a[i] - a[j]);
	}
	if (need <= C){
		printf("%lld", res);
		return 0;
	}

	head = new Node(a[0]);
	tail = head;

	for (int i = 1; i < n; ++i)
	if (a[i] == tail->h)
		++tail->cnt;
	else{
		node = new Node(a[i]);
		node->prev = tail;
		tail = (tail->next = node);
	}

	if (tail->h == head->h){
		head->cnt += tail->cnt;
		Node *temp = tail->prev;
		delete tail;
		(tail = temp)->next = NULL;
	}
	tail->next = head;
	head->prev = tail;

	Node *run = head;
	do {
		if (run->h < run->next->h && run->h < run->prev->h)
			heap.push(run);
		run = run->next;
	} while (run != head);

	res = 0;
	while (1){
		node = heap.top();
		heap.pop();
		int bound = min(node->next->h, node->prev->h) - node->h;
		if (bound * node->cnt < C){
			C -= bound * node->cnt;
			res += bound * 2;

			node->h += bound;
			run = node->next;
			while (run->h == node->h){
				node->cnt += run->cnt;
				Node *temp = run->next;
				node->next = temp;
				temp->prev = node;
				delete run;
				run = temp;
			}

			run = node->prev;
			while (run->h == node->h){
				node->cnt += run->cnt;
				Node *temp = run->prev;
				node->prev = temp;
				temp->next = node;
				delete run;
				run = temp;
			}

			if (node->h < node->next->h && node->h < node->prev->h)
				heap.push(node);
		}
		else{
			bound = C / node->cnt;
			res += bound * 2;
			break;
		}
	}

	printf("%lld\n", res);

	return 0;
}