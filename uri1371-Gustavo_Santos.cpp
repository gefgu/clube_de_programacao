#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n, i;

  while (scanf("%d", &n), n != 0)
  {
    for (i = 1; i * i <= n; i++)
    {
      if (i * i <= n)
        printf("%s%d", i < 2 ? "" : " ", i * i);
    }
    printf("\n");
  }

  return 0;
}