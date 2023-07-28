#include <bits/stdc++.h>

using namespace std;

map<string, int> representante_amizades;
map<string, string> pessoa_representante;
map<string, int> representante_rank;

string _find(string pessoa)
{
  if (pessoa_representante[pessoa] == pessoa)
    return pessoa;
  pessoa_representante[pessoa] = _find(pessoa_representante[pessoa]);
  return pessoa_representante[pessoa];
}

void _union(string u, string v)
{
  u = _find(u);
  v = _find(v);
  if (u == v)
    return;
  if (representante_rank[u] < representante_rank[v])
  {
    pessoa_representante[u] = v;
    representante_amizades[v] += representante_amizades[u];
  }
  else
  {
    pessoa_representante[v] = u;
    representante_amizades[u] += representante_amizades[v];
    if (representante_rank[u] == representante_rank[v])
      representante_rank[u]++;
  }
}

int main()
{
  int t, n;
  char a[30], b[30];

  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    while (n--)
    {
      scanf("%s %s", a, b);

      // make
      if (pessoa_representante.find(string(a)) == pessoa_representante.end())
      {
        pessoa_representante[string(a)] = string(a);
        representante_amizades[string(a)] = 1;
      }
      if (pessoa_representante.find(string(b)) == pessoa_representante.end())
      {
        pessoa_representante[string(b)] = string(b);
        representante_amizades[string(b)] = 1;
      }

      // union
      _union(string(a), string(b));

      // find
      printf("%d\n", representante_amizades[_find(string(a))]);
    }

    pessoa_representante.clear();
    representante_amizades.clear();
    representante_rank.clear();
  }

  return 0;
}