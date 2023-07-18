#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int explast(ll n, int k)
{
  if (k == 0)
    return 1;
  if (k & 1)
    return (n * explast(n, k - 1)) % 1000;
  int b = explast(n, k / 2);
  return (b * b) % 1000;
}

int first(int n)
{
  while (n > 1000)
    n /= 10;
  return n;
}

int expfirst(int n, int k)
{
  double a = k * log10(n);
  a -= (int)a;
  return (int)(pow(10, a) * 100);
}

int main()
{
  int t, k, l, f;
  ll n;

  scanf("%d", &t);

  while (t--)
  {
    scanf("%lld %d", &n, &k);
    l = explast(n, k);
    f = first(expfirst(n, k));
    printf("%d...%0*d\n", f, 3, l);
  }

  return 0;
}