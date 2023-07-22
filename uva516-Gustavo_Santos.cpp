#include <bits/stdc++.h>

using namespace std;

#define MAX 1123

int p[MAX], pi, f[MAX], mults[MAX], k;

void sieve()
{
  int i, j, primo, r;

  p[0] = 2;
  pi = 1;
  for (i = 3; i < MAX; i++)
  {
    primo = 1;
    r = sqrt(i);
    for (j = 0; j < pi && p[i] <= r && primo; j++)
      if (i % p[j] == 0)
        primo = 0;

    if (primo)
      p[pi++] = i;
  }
}

int expbin(int b, int e)
{
  if (e == 0)
    return 1;
  if (e & 1)
    return b * expbin(b, e - 1);
  int y = expbin(b, e / 2);
  return y * y;
}

int main()
{
  int b, e, t, n, i, first;
  char line[MAX];
  char *c;

  sieve();

  while (fgets(line, MAX, stdin) != NULL)
  {
    n = 1;
    first = 1;
    k = 0;
    for (c = line; sscanf(c, "%d %d%n", &b, &e, &t) == 2; c += t)
      n *= expbin(b, e);
    n--;

    if (b == 0 || e == 0)
      break;

    for (i = 0; i < pi && p[i] * p[i] <= n; i++)
    {
      if (n % p[i] == 0)
      {
        mults[k] = 0;
        while (n % p[i] == 0)
        {
          n /= p[i];
          mults[k]++;
        }
        f[k++] = p[i];
      }
    }

    if (n > 1)
    {
      f[k] = n;
      mults[k++] = 1;
    }

    while (k--)
    {
      printf("%s%d %d", first ? "" : " ", f[k], mults[k]);
      first = 0;
    }
    printf("\n");
  }

  return 0;
}