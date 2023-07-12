#include <bits/stdc++.h>

int main()
{

  char texto[256];
  float salario_fixo, vendas;

  scanf("%s", texto);
  scanf("%f %f", &salario_fixo, &vendas);

  printf("TOTAL = R$ %.2f\n", (salario_fixo + (vendas * 0.15)));

  return 0;
}