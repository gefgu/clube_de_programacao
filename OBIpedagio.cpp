#include <bits/stdc++.h>

using namespace std;

int main()
{
  int l, d, k, p;
  scanf("%d %d %d %d", &l, &d, &k, &p);

  int ans = (l / d) * p + (l * k);

  printf("%d\n", ans);

  return 0;
}