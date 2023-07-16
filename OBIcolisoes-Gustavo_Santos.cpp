#include <bits/stdc++.h>

using namespace std;

int main()
{

  int ax_0, ay_0, ax_1, ay_1;
  int bx_0, by_0, bx_1, by_1;

  scanf("%d %d %d %d", &ax_0, &ay_0, &ax_1, &ay_1);
  scanf("%d %d %d %d", &bx_0, &by_0, &bx_1, &by_1);

  int ans = 0;

  if (bx_0 <= ax_1 && by_0 <= ay_1 && bx_1 >= ax_0 && by_1 >= ay_0)
    ans = 1;

  printf("%d\n", ans);

  return 0;
}