#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define P 131071

ll expbin(ll b, int e)
{
  if (e == 0)
    return 1;
  if (e & 1)
    return (b * expbin(b, e - 1)) % P;
  ll y = expbin(b, e / 2);
  return (y * y) % P;
}

int main()
{
  char b[11234];
  int tam;
  int i, pot;
  char d;
  ll r;

  while (scanf(" %c", &d) != EOF)
  {
    b[0] = d;
    tam = 1;
    while (scanf("%c", &d), d != '#')
    {
      if (d != '\n')
      {
        b[tam] = d;
        tam++;
      }
    }

    pot = tam - 1;
    r = 0;
    for (i = 0; i < tam; i++)
    {
      if (b[i] == '1')
      {
        r += expbin(2, (pot - i) % 17);
        r %= P;
      }
    }

    printf("%s\n", r == 0 ? "YES" : "NO");
  }

  return 0;
}