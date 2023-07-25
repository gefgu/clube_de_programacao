#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m, q, s, i, j, soma, k, l, flag, quadrado[212][212];

  scanf("%d %d", &n, &m);

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
    {
      scanf("%d", &quadrado[i][j]);
      quadrado[i][j] = quadrado[i][j] > 0;
    }

  int max = min(n, m), min = 0;
  while (max != min)
  {
    flag = 0;
    s = max - min > 1 ? (min + max) / 2 : max;
    for (i = 0; i <= n - s && !flag; i++)
      for (j = 0; j <= m - s && !flag; j++)
      {
        soma = 0;
        for (k = i; k < i + s && !flag; k++)
          for (l = j; l < j + s && !flag; l++)
            soma += quadrado[k][l];

        flag = soma == s * s;
      }
    if (flag)
      min = s;
    else
      max = s - 1;
  }

  scanf("%d", &q);
  while (q--)
  {
    scanf("%d", &s);

    printf("%s\n", s <= max ? "yes" : "no");
  }

  return 0;
}