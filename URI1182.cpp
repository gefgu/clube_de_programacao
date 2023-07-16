#include <bits/stdc++.h>

int main()
{
  int l, i, j;
  char t;
  float soma = 0;
  float a;

  scanf("%d %c", &l, &t);
  for (i = 0; i < 12; i++)
  {
    for (j = 0; j < 12; j++)
    {
      scanf("%f", &a);
      if (j == l)
        soma += a;
    }
  }

  printf("%.1f\n", t == 'S' ? soma : soma / 12.);

  return 0;
}