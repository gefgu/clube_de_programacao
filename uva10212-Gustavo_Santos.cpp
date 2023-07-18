#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1000000000

ll last(ll a)
{
  while (a % 10 == 0 && a > 0)
    a /= 10;
  return a % MAX;
}

int solve(int n, int m)
{
  ll ans = 1;
  int i;
  for (i = n; i > n - m; i--)
  {
    ans *= i;
    ans = last(ans);
  }

  return ans % 10;
}

int main()
{

  int n, m;

  while (scanf("%d %d", &n, &m) != EOF)
  {
    int ans = solve(n, m);
    printf("%d\n", ans);
  }

  return 0;
}