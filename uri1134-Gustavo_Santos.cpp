#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n;
  int alcool = 0, gasolina = 0, diesel = 0;

  while (scanf("%d", &n), n != 4)
  {
    if (n == 1)
    {
      alcool++;
    }
    else if (n == 2)
    {
      gasolina++;
    }
    else if (n == 3)
    {
      diesel++;
    }
  }

  printf("MUITO OBRIGADO\n");
  printf("Alcool: %d\nGasolina: %d\nDiesel: %d\n", alcool, gasolina, diesel);

  return 0;
}