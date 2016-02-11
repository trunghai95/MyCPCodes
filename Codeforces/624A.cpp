#include <bits/stdc++.h>

using namespace std;

double d, L, v1, v2;

int main()
{
	scanf("%lf %lf %lf %lf", &d, &L, &v1, &v2);
	printf("%.12lf", (L-d)/(v1+v2));
	return 0;
}