#include <bits/stdc++.h>

int main()
{

  int numero, horas;
  float qty;

  scanf("%d %d", &numero, &horas);

  scanf("%f", &qty);

  printf("NUMBER = %d\nSALARY = U$ %.2f\n", numero, qty * horas);

  return 0;
}