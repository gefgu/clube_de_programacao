#include <bits/stdc++.h>

using namespace std;

#define MAX 2000008

typedef long long ll;

// Ideia: Um hiperprimo n é da forma n = p^{alfa}, onde alfa = <algum primo> - 1

int p[MAX], pi, res[MAX];

void sieve()
{
  int i, j, r, primo;
  p[0] = 2;
  pi = 1;

  for (i = 3; i < MAX * 2; i++)
  {
    r = sqrt(i);
    primo = 1;
    for (j = 0; j < pi && p[j] <= r && primo; j++)
      if (i % p[j] == 0)
        primo = 0;
    if (primo)
      p[pi++] = i;
  }
}

ll expbin(ll b, ll e)
{
  if (e == 0)
    return 1;
  if (e & 1)
    return b * expbin(b, e - 1);
  ll y = expbin(b, e / 2);
  return y * y;
}

void solve()
{
  ll i, j, k;
  memset(res, 0, sizeof(res));
  for (i = 0; i < pi; i++)
    for (j = 0; k = expbin(p[i], p[j] - 1), j < pi && k <= MAX && k > 0; j++)
      res[k] = 1;

  for (i = 1; i < MAX; i++)
    res[i] += res[i - 1];
}

int main()
{
  int n;

  sieve();

  solve();

  while (scanf("%d", &n) != EOF)
  {
    printf("%d\n", res[n]);
  }

  return 0;
}