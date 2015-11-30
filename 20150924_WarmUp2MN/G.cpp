#include <bits/stdc++.h>
using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
	coord_t x, y;

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}

	Point(int a, int b): x(a), y(b) {}
	Point() {}
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> &P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

int main()
{
    int test, tt, n;
    vector<Point> in, res;

    cin >> test;
    while (test--)
    {
        cin >> tt >> n;
        in.clear(); res.clear();
        for (int i = 0, u, v; i < n; ++i)
        {
            cin >> u >> v;
            in.push_back(Point(u,v));
        }

        res = convex_hull(in);
        res.pop_back();

        int pos = 0;

        for (int i = 1; i < res.size(); ++i)
        {
            if (res[i].y > res[pos].y || (res[i].y == res[pos].y && res[i].x < res[pos].x))
                pos = i;
        }

        cout << tt << ' ' << res.size() << endl;
        for (int i = pos; i >= 0; --i)
        {
            cout << res[i].x << ' ' << res[i].y << endl;
        }

        for (int i = res.size() - 1; i > pos; --i)
        {
            cout << res[i].x << ' ' << res[i].y << endl;
        }
    }
}
