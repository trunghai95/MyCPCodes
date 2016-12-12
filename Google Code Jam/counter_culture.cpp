#include <cstdio>
#include <cstdlib>

#include <string>
#include <algorithm>

using namespace std;

long long p10[10];  // p10[i] == 10^i

bool is_1_followed_by_0s(string S) {
  reverse(S.begin(), S.end());
  return atoi(S.c_str()) == 1;
}

int solve(long long N) {
  if (N < 10) return N;  // Trivial case.

  char X[20]; sprintf(X, "%lld", N);
  string S = X;
  int M = S.length();  // Number of digits of N.

  // Starts from 1.
  int ans = 1;

  // Part 1: from 1, get to the M digits as fast as possible.
  for (int d = 1; d < M; d++) {
    // For digits = 7, it starts from 7 digits:    1000000
    ans += p10[(d + 1) / 2] - 1; // Count up 9999: 1009999
    if (d > 1) ans++;            // Flip once:     9999001
    ans += p10[d / 2] - 1;       // Count up 999: 10000000
  }


  // Part 2:

  // Split N into two halves. For example N = "1234567"
  string L = S.substr(0, M / 2);  // L = "123"
  string R = S.substr(M / 2);     // R = "4567"

  // Handles the case where the right half is all zeroes.
  if (atoi(R.c_str()) == 0) return solve(N - 1) + 1;

  // Special case: Count directly to the answer.
  if (is_1_followed_by_0s(L))
    return ans + atoi(R.c_str());

  // Count until the right half looks like the left half of N
  // in reverse. In this case, count from 1000000 to 1000321.
  reverse(L.begin(), L.end());
  ans += atoi(L.c_str());

  // Flip 1000321 to 1230001.
  ans++;

  // Count up 4566 to the target from 1230001 to 1234567.
  ans += atoi(R.c_str()) - 1;
  return ans;
}

int main() {
  p10[0] = 1;
  for (int i = 1; i < 10; i++)
    p10[i] = p10[i - 1] * 10;

  long long T, N;
  scanf("%lld", &T);
  for (int TC = 1; TC <= T; TC++) {
    scanf("%lld", &N);
    printf("Case #%d: %d\n", TC, solve(N));
  }
}
