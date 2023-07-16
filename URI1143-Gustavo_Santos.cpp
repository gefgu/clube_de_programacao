#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n;

  scanf("%d", &n);

  int i;

  for (i = 1; i <= n; i++)
  {
    printf("%d %d %d\n", i, i * i, i * i * i);
  }

  return 0;
}