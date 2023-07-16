#include <bits/stdc++.h>

using namespace std;

int main()
{

  int x, y;

  scanf("%d %d", &x, &y);

  if (x > y)
    swap(x, y);

  int i;
  for (i = x + 1; i % 5 != 2 && i % 5 != 3; i++)
    ;
  while (i < y)
  {
    printf("%d\n", i);
    if (i % 5 == 2)
    {
      i++;
    }
    else
    {
      i += 4;
    }
  }

  return 0;
}