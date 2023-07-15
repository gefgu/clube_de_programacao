#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  int pa, pb;
  float ga, gb;

  scanf("%d", &n);

  int i;
  while (n--)
  {
    scanf("%d %d %f %f", &pa, &pb, &ga, &gb);
    for (i = 0; i <= 100 && pb >= pa; i++)
    {
      pa += (int)pa * (ga / 100.0);
      pb += (int)pb * (gb / 100.0);
    }
    if (i > 100)
    {
      printf("Mais de 1 seculo.\n");
    }
    else
    {
      printf("%d anos.\n", i);
    }
  }

  return 0;
}