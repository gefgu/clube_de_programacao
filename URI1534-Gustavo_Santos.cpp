#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n, i, j, a;

  while (scanf("%d", &n) != EOF)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        a = j + i == n - 1 ? 2 : j == i ? 1
                                        : 3;
        printf("%d", a);
      }
      printf("\n");
    }
  }

  return 0;
}