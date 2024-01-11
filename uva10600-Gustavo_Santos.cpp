#include <bits/stdc++.h>

#define MAX 312
#define INF 11234567

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int _p[MAX], _rank[MAX];
vector<iii> eg;

int _find(int u) { return _p[u] == u ? u : (_p[u] = _find(_p[u])); }

void _union(int u, int v)
{
  u = _find(u);
  v = _find(v);
  if (_rank[u] < _rank[v])
    _p[u] = v;
  else
  {
    _p[v] = u;
    if (_rank[u] == _rank[v])
      _rank[u]++;
  }
}

void kruskal(int n)
{
  int u, v, i, val, flag, p;
  int minimum = 0, second_minimum = INF;
  vector<ii> marked_edges;

  for (u = 0; u <= n; u++)
  {
    _p[u] = u;
    _rank[u] = 0;
  }

  sort(eg.begin(), eg.end());
  for (auto &[wei, e] : eg)
  {
    tie(u, v) = e;
    if (_find(u) != _find(v))
    {
      marked_edges.push_back(ii(u, v));
      _union(u, v);
      minimum += wei;
    }
  }

  for (auto &[a, b] : marked_edges)
  {
    val = 0;

    for (u = 0; u <= n; u++)
    {
      _p[u] = u;
      _rank[u] = 0;
    }

    for (auto &[wei, e] : eg)
    {
      tie(u, v) = e;
      if (u == a && v == b)
        continue;
      if (_find(u) != _find(v))
      {
        _union(u, v);
        val += wei;
      }
    }

    flag = 1;
    for (u = 1; u <= n; u++)
      if (_find(1) != _find(u))
        flag = 0;

    if (flag && val < second_minimum)
      second_minimum = val;
  }

  printf("%d %d\n", minimum, second_minimum);
}

int main()
{
  int t, n, m, a, b, c, i;

  scanf("%d", &t);

  while (t--)
  {
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
      scanf("%d %d %d", &a, &b, &c);
      eg.push_back(iii(c, ii(a, b)));
    }

    kruskal(n);

    eg.clear();
  }

  return 0;
}