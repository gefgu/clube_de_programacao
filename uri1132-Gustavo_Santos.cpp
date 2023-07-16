#include <bits/stdc++.h>

using namespace std;

int main()
{

  int x, y;

  scanf("%d %d", &x, &y);
  if (x > y)
    swap(x, y);

  int soma = ((x + y) * (y - x + 1)) / 2;
  int i;
  for (i = x + (13 - (x % 13)); i <= y; i += 13)
  {
    soma -= i;
  }

  printf("%d\n", soma);

  return 0;
}