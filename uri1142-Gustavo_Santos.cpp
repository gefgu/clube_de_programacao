#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n;

  scanf("%d", &n);

  int i = 1;
  while (n--)
  {
    printf("%d %d %d PUM\n", i, i + 1, i + 2);
    i += 4;
  }

  return 0;
}