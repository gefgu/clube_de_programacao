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
        a = 1 + min(j, min(n - j - 1, min(n - i - 1, i)));
        printf("%*d%s", 3, a, j == n - 1 ? "" : " ");
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}