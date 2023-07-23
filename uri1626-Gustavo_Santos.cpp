#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007
#define MAX 112345

int p[MAX], pi;

void sieve()
{
  int i, j, r, primo;
  p[0] = 2;
  pi = 1;

  for (i = 3; i < MAX; i++)
  {
    primo = 1;
    r = sqrt(i);
    for (j = 0; j < pi && p[j] <= r && primo; j++)
      if (i % p[j] == 0)
        primo = 0;

    if (primo)
      p[pi++] = i;
  }
}

ll fact(ll a)
{
  if (a == 1)
    return 1;
  return (a * fact(a - 1)) % MOD;
}

int nExpoente(int n, int p)
{
  int expoente = 0;
  ll power = p;
  while (n >= power)
  {
    expoente += n / power;
    power *= p;
  }

  return expoente;
}

ll expbin(int b, int e)
{
  if (e == 0)
    return 1;
  if (e & 1)
    return (b * expbin(b, e - 1)) % MOD;
  ll y = expbin(b, e / 2);
  return (y * y) % MOD;
}

ll sum(ll n, ll f)
{
  int mults[MAX], k, i;
  ll sum = 1;

  for (i = 0; i < pi && p[i] <= n; i++)
    mults[i] = nExpoente(n, p[i]);
  k = i;

  for (i = 0; i < k; i++)
  {
    sum *= (expbin(p[i], mults[i] + 1) - 1) % MOD;
    sum %= MOD;
    sum *= expbin((p[i] - 1), MOD - 2) % MOD;
    sum %= MOD;
  }

  return (((sum - f) % MOD) + MOD) % MOD;
}

int main()
{
  ll n, s, f;

  sieve();

  while (scanf("%lld", &n) != EOF)
  {
    f = fact(n);
    s = sum(n, f);
    printf("%lld %lld\n", s, f);
  }

  return 0;
}