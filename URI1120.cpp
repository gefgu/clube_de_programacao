#include <bits/stdc++.h>

using namespace std;

int main()
{
  char d;
  char alg;
  int flag, eh_zero;

  while (scanf("%c", &d), d != '0')
  {
    flag = 0;
    eh_zero = 0;
    while (scanf("%c", &alg), alg != '\n')
    {
      if (!flag)
      {
        if (alg == '0')
        {
          eh_zero = 1;
        }
        else if (alg >= '1' && alg <= '9' && alg != d)
        {
          putchar(alg);
          flag = 1;
          eh_zero = 0;
        }
      }
      else if (alg >= '0' && alg <= '9' && alg != d)
      {
        putchar(alg);
      }
    }
    if (eh_zero || !flag)
      printf("0\n");
    else
      printf("\n");
  }

  return 0;
}