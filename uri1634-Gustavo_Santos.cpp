#include <bits/stdc++.h>

using namespace std;

#define MAX 112345

int euclid(int a, int b)
{
  if (b == 0)
    return a;
  return euclid(b, a % b);
}

int main()
{
  int n, m;
  int vet[MAX];
  int i, j, x;
  int total;
  int d;

  while (scanf("%d %d", &n, &m), n != 0 && m != 0)
  {
    total = 0;
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m - 1; j++)
        scanf("%d", &x);
      scanf("%d", &vet[i]);
      total += vet[i];
    }

    for (i = 0; i < n; i++)
    {
      if (vet[i] == 0)
        printf("0 / 1\n");
      else
      {
        d = euclid(total, vet[i]);
        printf("%d / %d\n", vet[i] / d, total / d);
      }
    }
  }

  return 0;
}