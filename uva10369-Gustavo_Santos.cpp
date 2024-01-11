#include <bits/stdc++.h>

#define MAX 512

using namespace std;

typedef pair<int, int> ii;
typedef pair<float, ii> iii;
int _p[MAX], _rank[MAX];
ii outposts[MAX];
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

float distance(ii u, ii v)
{
  return sqrt((u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second));
}

void build_eg(int p)
{
  int i, j;
  float dis;
  for (i = 0; i < p; i++)
    for (j = i + 1; j < p; j++)
    {
      dis = distance(outposts[i], outposts[j]);
      eg.push_back(iii(dis, ii(i, j)));
    }
}

float kruskal(int n, int s)
{
  int u, v;
  int forests = n;
  float maximum = 0;

  for (u = 0; u < n; u++)
  {
    _p[u] = u;
    _rank[u] = 1;
  }

  sort(eg.begin(), eg.end());
  for (auto &[wei, e] : eg)
  {
    tie(u, v) = e;
    if (_find(u) != _find(v))
    {
      _union(u, v);
      forests--;
      if (wei > maximum)
        maximum = wei;
      if (forests == s)
        return maximum;
    }
  }

  return maximum;
}

int main()
{
  int n, s, p, x, y;
  scanf("%d", &n);

  while (n--)
  {
    scanf("%d %d", &s, &p);

    for (int i = 0; i < p; i++)
      scanf("%d %d", &outposts[i].first, &outposts[i].second);

    build_eg(p);
    printf("%.2f\n", kruskal(p, s));
    eg.clear();
  }

  return 0;
}