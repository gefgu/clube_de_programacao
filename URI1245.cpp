#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n, tamanho, total;
  int D[70], E[70];
  char lado;

  int i;

  while (scanf("%d", &n) != EOF)
  {
    for (i = 30; i <= 60; i++)
    {
      D[i] = 0;
      E[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
      scanf("%d %c", &tamanho, &lado);
      lado == 'D' ? D[tamanho]++ : E[tamanho]++;
    }

    total = 0;
    for (i = 30; i <= 60; i++)
    {
      total += min(D[i], E[i]);
    }
    printf("%d\n", total);
  }

  return 0;
}