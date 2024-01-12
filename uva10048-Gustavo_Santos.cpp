#include <bits/stdc++.h>

#define MAX 112

using namespace std;

typedef pair<int, int> ii;
typedef pair<float, ii> iii;

int _p[MAX], _rank[MAX];
vector<iii> eg;
vector<ii> al[MAX];

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
  int u, v;
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
      _union(u, v);
      al[u].push_back(ii(v, wei));
      al[v].push_back(ii(u, wei));
    }
  }
}

int bfs(int s, int d)
{
  queue<int> q;
  q.push(s);
  map<int, int> dict;
  dict[s] = 0;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (auto &[v, wei] : al[u])
    {
      if (dict.find(v) == dict.end())
      {
        dict[v] = max(wei, dict[u]);
        if (v == d)
          return dict[v];
        q.push(v);
      }
    }
  }

  return -1;
}

int main()
{

  int c, s, q;
  int u, v, wei, i;
  int caso = 1;
  int first = 1;

  while (scanf("%d %d %d", &c, &s, &q), c != 0 && s != 0 && q != 0)
  {
    for (i = 0; i < s; i++)
    {
      scanf("%d %d %d", &u, &v, &wei);
      eg.push_back(iii(wei, ii(u, v)));
    }

    kruskal(c);

    if (!first)
      printf("\n");
    printf("Case #%d\n", caso);
    for (i = 0; i < q; i++)
    {
      scanf("%d %d", &u, &v);
      int m = bfs(u, v);
      if (m == -1)
        printf("no path\n");
      else
        printf("%d\n", m);
    }

    caso++;
    eg.clear();
    for (i = 0; i <= MAX; i++)
      al[i].clear();

    first = 0;
  }

  return 0;
}