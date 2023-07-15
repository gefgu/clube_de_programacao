#include <bits/stdc++.h>

using namespace std;

int main()
{

  double maior = 0;
  int n, n_maior;
  int d, c;
  double grandeza;

  scanf("%d", &n);

  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d %d", &d, &c);
    grandeza = c * log(d);
    if (grandeza > maior)
    {
      maior = grandeza;
      n_maior = i;
    }
  }

  printf("%d\n", n_maior);

  return 0;
}