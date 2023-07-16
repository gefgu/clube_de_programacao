#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, i, j;
  int a;

  while (scanf("%d", &n), n)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        a = 1 + abs(i - j);
        printf("%*d%s", 3, a, j == n - 1 ? "" : " ");
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}