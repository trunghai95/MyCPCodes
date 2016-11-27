#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int MAX = 1e3 + 1;
int test, k, n[3], a[3][MAX], cntZero1, cntZero2;
int szNeg, szZero;
int pos[2][MAX * MAX];
int pi1[2][MAX * MAX], sz1[2], pi2[2][MAX], sz2[2];

struct Node{
    int val, id, type;
    Node() {}
    Node(const int& val, const int& id, const int& type) :
        val(val), id(id), type(type) {}
};

struct cmp{
    bool operator () (const Node& x, const Node& y){
        return x.val > y.val;
    }
};
priority_queue <Node, vector <Node>, cmp> heap;

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &test);
    while (test--){
        scanf("%d %d %d %d", n, n + 1, n + 2, &k);
        for (int type = 0; type < 3; ++type)
        for (int i = 1; i <= n[type]; ++i)
            scanf("%d", &a[type][i]);
            //a[type][i] = i;

        /*
        vector <int> cache;
        for (int i0 = 1; i0 <= n[0]; ++i0)
        for (int i1 = 1; i1 <= n[1]; ++i1)
        for (int i2 = 1; i2 <= n[2]; ++i2)
            cache.push_back(a[0][i0] * a[1][i1] * a[2][i2]);
        sort(cache.begin(), cache.end());
        for (int i : cache)
            printf("%d ", i);
        printf("\n");
        printf("Correct %d\n", cache[k - 1]);
        */

        sz1[0] = sz1[1] = sz2[0] = sz2[1] = 0;
        cntZero1 = cntZero2 = 0;
        for (int i = 1; i <= n[0]; ++i)
        for (int j = 1; j <= n[1]; ++j)
        if (a[0][i] * a[1][j] == 0)
            ++cntZero1;
        else
        if (a[0][i] * a[1][j] > 0)
            pi1[0][sz1[0]++] = a[0][i] * a[1][j];
        else
            pi1[1][sz1[1]++] = a[0][i] * a[1][j];

        //sort(a[2] + 1, a[2] + n[2] + 1);
        for (int i = 1; i <= n[2]; ++i)
        if (a[2][i] == 0)
            ++cntZero2;
        else
        if (a[2][i] > 0)
            pi2[0][sz2[0]++] = a[2][i];
        else
            pi2[1][sz2[1]++] = a[2][i];

        szZero = cntZero1 * n[2] + cntZero2 * n[0] * n[1] - cntZero1 * cntZero2;
        szNeg = sz1[0] * sz2[1] + sz1[1] * sz2[0];
        if (k > szNeg && k <= szNeg + szZero){
            printf("0\n");
            continue;
        }

        while (!heap.empty())
            heap.pop();
        Node node;
        int newP;
        if (k <= szNeg){
            sort(pi2[1], pi2[1] + sz2[1]);
            if (sz2[1] > 0)
            for (int i = 0; i < sz1[0]; ++i){
                pos[0][i] = 0;
                heap.push(Node(pi1[0][i] * pi2[1][0], i, 0));
            }

            sort(pi2[0], pi2[0] + sz2[0], greater<int>());
            if (sz2[0] > 0)
            for (int i = 0; i < sz1[1]; ++i){
                pos[1][i] = 0;
                heap.push(Node(pi1[1][i] * pi2[0][0], i, 1));
            }

            while (k--){
                node = heap.top();
                heap.pop();
                if (node.type == 0){
                    if (pos[0][node.id] + 1 < sz2[1]){
                        newP = ++pos[0][node.id];
                        heap.push(Node(pi1[0][node.id] * pi2[1][newP], node.id, 0));
                    }
                }
                else{
                    if (pos[1][node.id] + 1 < sz2[0]){
                        newP = ++pos[1][node.id];
                        heap.push(Node(pi1[1][node.id] * pi2[0][newP], node.id, 1));
                    }
                }
            }
            printf("%d\n", node.val);
        }
        else{
            k -= szNeg + szZero;
            sort(pi2[0], pi2[0] + sz2[0]);
            if (sz2[0] > 0)
            for (int i = 0; i < sz1[0]; ++i){
                pos[0][i] = 0;
                heap.push(Node(pi1[0][i] * pi2[0][0], i, 0));
            }

            sort(pi2[1], pi2[1] + sz2[1], greater<int>());
            if (sz2[1] > 0)
            for (int i = 0; i < sz1[1]; ++i){
                pos[1][i] = 0;
                heap.push(Node(pi1[1][i] * pi2[1][0], i, 1));
            }

            while (k--){
                node = heap.top();
                heap.pop();
                if (node.type == 0){
                    if (pos[0][node.id] + 1 < sz2[0]){
                        newP = ++pos[0][node.id];
                        heap.push(Node(pi1[0][node.id] * pi2[0][newP], node.id, 0));
                    }
                }
                else{
                    if (pos[1][node.id] + 1 < sz2[1]){
                        newP = ++pos[1][node.id];
                        heap.push(Node(pi1[1][node.id] * pi2[1][newP], node.id, 1));
                    }
                }
            }
            printf("%d\n", node.val);
        }
    }
    return 0;
}
