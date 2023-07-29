#include <bits/stdc++.h>

using namespace std;

#define MAX 112345

int bit[MAX], n;

void _update(int i, int val)
{
  while (i <= n)
  {
    bit[i] += val;
    i += i & -i;
  }
}

int _get(int i)
{
  int ans = 0;
  while (i > 0)
  {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

int main()
{

  int i, x, pessoas_buggie[MAX];
  char c;

  memset(bit, 0, sizeof(bit));

  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &x);
    pessoas_buggie[i] = x;
    _update(i, x);
  }

  while (scanf(" %c %d", &c, &x) != EOF)
  {
    if (c == 'a')
      _update(x, -pessoas_buggie[x]);
    if (c == '?')
      printf("%d\n", _get(x) - pessoas_buggie[x]);
  }

  return 0;
}