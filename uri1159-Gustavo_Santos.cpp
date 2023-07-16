#include <bits/stdc++.h>

using namespace std;

int main()
{

  int x, ans;

  while (scanf("%d", &x), x != 0)
  {
    if (abs(x % 2) == 1)

      x++;

    ans = ((x + x + 8) * 5) / 2;
    printf("%d\n", ans);
  }

  return 0;
}