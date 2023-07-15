#include <bits/stdc++.h>

using namespace std;

int main()
{
  int c, p, f;

  scanf("%d %d %d", &c, &p, &f);

  printf("%s\n", c * f > p ? "N" : "S");

  return 0;
}