#include <bits/stdc++.h>

using namespace std;

int x, y;

int mod(int n, int m)
{
  return ((n % m) + m) % m;
}

int extEuclid(int a, int b)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  int d = extEuclid(b, a % b);
  int x_ = x;
  x = y;
  y = x_ - y * (a / b);
  return d;
}

int inv(int b, int m)
{
  extEuclid(m, b);

  return y;
}

int main()
{
  int p, e, i, d, r;
  int x, j = 1;
  int mt = 23 * 28 * 33;

  while (scanf("%d %d %d %d", &p, &e, &i, &d), p != -1)
  {
    x = 0;

    r = p * (mt / 23) * inv(mt / 23, 23);
    x = mod(r, mt);
    x = mod(x, mt);

    r = e * (mt / 28) * inv(mt / 28, 28);
    x += mod(r, mt);
    x = mod(x, mt);

    r = i * (mt / 33) * inv(mt / 33, 33);
    x += mod(r, mt);
    x = mod(x, mt);

    if (x <= d)
      x += mt;

    printf("Case %d: the next triple peak occurs in %d days.\n", j++, x - d <= mt ? x - d : mt);
  }

  return 0;
}