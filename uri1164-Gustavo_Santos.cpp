#include <bits/stdc++.h>

using namespace std;

int ehPerfeito(int x)
{
  if (x == 1)
  {
    return 0;
  }
  int soma = 1;
  int i;

  for (i = 2; i < sqrt(x); i++)
  {
    if (x % i == 0)
    {
      soma += i;
      soma += x / i;
    }
  }

  return x == soma;
}

int main()
{
  int n, x;

  scanf("%d", &n);

  while (n--)
  {
    scanf("%d", &x);
    printf("%d%s eh perfeito\n", x, ehPerfeito(x) ? "" : " nao");
  }

  return 0;
}