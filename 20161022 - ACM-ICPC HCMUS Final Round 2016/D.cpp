#include <stdio.h>
 
typedef long long ll;
const int maxn = 5010;
int n, k, st[maxn], las, fir;
ll sum[maxn], f[maxn], res[maxn], save[maxn];
int tra[110][maxn];
struct {
	int id;
	ll a, b;
} val[maxn];
 
//ll tmp[11][maxn];
 
int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= n; i++){
		ll val;
		scanf("%lld", &val);
		sum[i] = sum[i - 1] + val;
		f[i] = f[i - 1] + val * i;
	}

	if (k >= n){
		printf("%lld\n", sum[n]);
		for (int i = n + 1; i <= k; ++i)
			printf("0 ");
		for (int i = 1; i <= n; ++i)
			printf("1 ");
		return 0;
	}
 
	/*for (int i = 1; i <= n; i++)
		tmp[1][i] = f[i] - sum[i];
	for (int t = 2; t <= k; t++)
	for (int i = t; i <= n; i++){
		tmp[t][i] = 1e18;
		for (int j = t; j <= i; j++)
			tmp[t][i] = min(tmp[t][i], f[i] - f[j] - (sum[i] - sum[j]) * j + tmp[t - 1][j - 1]);
	}
	printf("\n%I64d\n", tmp[k][n]);
	*/
 
	for (int i = n; i >= k; i--){
		res[i] = f[n] - f[i - 1] - (sum[n] - sum[i - 1]) * (i - 1);
		tra[1][i] = n;
	}
 
	for (int t = 2; t <= k; t++){
		las = 0;
		fir = 1;
		for (int i = n - t + 1; i >= k - t + 1; i--){
			val[i].a = -sum[i];
			val[i].b = f[i] + res[i + 1] + sum[i];
			val[i].id = i;
			while (las > fir && 
				(val[i].b - val[st[las]].b) * (val[i].a - val[st[las - 1]].a) <= (val[i].a - val[st[las]].a) * (val[i].b - val[st[las - 1]].b))
				las--;
			st[++las] = i;
			while (fir < las && (val[st[fir + 1]].a * i + val[st[fir + 1]].b <= val[st[fir]].a * i + val[st[fir]].b))
				fir++;

			save[i] = val[st[fir]].a * i + val[st[fir]].b - f[i] + i * sum[i] - sum[i - 1];
			tra[t][i] = val[st[fir]].id;			
		}
		for (int i = n - t + 1; i >= k - t + 1; i--)
			res[i] = save[i];
	}
	printf("%lld\n", res[1]);
	int pos = 1;
	for (int i = k; i >= 1; --i){
		printf("%d ", tra[i][pos] - pos + 1);
		pos = tra[i][pos] + 1;
	}
	return 0;
}