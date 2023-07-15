#include <bits/stdc++.h>

using namespace std;

int main()
{

  float soma = 0;

  int i;
  int pot_2 = 1;
  for (i = 1; i <= 39; i += 2)
  {
    soma += i / (float)pot_2;
    pot_2 *= 2;
  }

  printf("%.2f\n", soma);

  return 0;
}