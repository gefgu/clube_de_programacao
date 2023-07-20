#include <bits/stdc++.h>

using namespace std;

#define MAX 1123456

int p[MAX], pi;

void sieve()
{
  int i, j, r, primo;
  pi = 0;
  p[pi++] = 2;
  for (i = 3; i < MAX; i++)
  {
    primo = 1;
    r = sqrt(i);
    for (j = 0; j < pi && primo && p[j] <= r; j++)
      if (i % p[j] == 0)
        primo = 0;
    if (primo)
      p[pi++] = i;
  }
}

int main()
{
  int n, a, b, d, flag, i, j;

  sieve();

  while (scanf("%d", &n), n != 0)
  {
    flag = 0;
    for (i = 0; p[i] <= n; i++)
      ;
    for (i = i; i > 0 && !flag; i--)
    {
      d = n - p[i];
      for (j = 0; p[j] <= d && !flag && j <= i; j++)
        if (p[j] == d)
        {
          flag = 1;
          a = j;
          b = i;
        }
    }

    if (flag)
    {
      printf("%d = %d + %d\n", n, p[a], p[b]);
    }
    else
    {
      printf("Goldbach's conjecture is wrong.\n");
    }
  }
}