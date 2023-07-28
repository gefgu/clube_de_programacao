#include <bits/stdc++.h>

using namespace std;

#define MAX 112

int _p[MAX], _rank[MAX];

int _find(int a)
{
  if (_p[a] == a)
    return a;
  _p[a] = _find(_p[a]);
  return _p[a];
}

void _union(int a, int b)
{
  a = _find(a);
  b = _find(b);
  if (_rank[a] < _rank[b])
    _p[a] = b;
  else
  {
    _p[b] = a;
    if (_rank[a] == _rank[b])
      _rank[a]++;
  }
}

int main()
{
  int t, n, m, x, y, i, j;
  set<int> unique;

  scanf("%d", &t);

  for (j = 1; j <= t; j++)
  {
    scanf("%d %d", &n, &m);

    for (i = 0; i <= n; i++)
    {
      _p[i] = i;
      _rank[i] = 0;
    }

    while (m--)
    {
      scanf("%d %d", &x, &y);
      _union(x, y);
    }

    for (i = 1; i <= n; i++)
      unique.insert(_find(i));

    printf("Caso #%d:", j);
    if (unique.size() > 1)
      printf(" ainda falta(m) %d estrada(s)\n", (int)unique.size() - 1);
    else
      printf(" a promessa foi cumprida\n");

    unique.clear();
  }

  return 0;
}