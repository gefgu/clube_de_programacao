#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll expbin(ll b, ll p, ll m)
{
  if (p == 0)
    return 1;
  if (p & 1)
    return (b * expbin(b, p - 1, m)) % m;
  ll y = expbin(b, p / 2, m);
  return (y * y) % m;
}

int main()
{

  ll b, p, m;

  while (scanf("%lld %lld %lld", &b, &p, &m) != EOF)
  {
    printf("%lld\n", expbin(b, p, m));
  }

  return 0;
}