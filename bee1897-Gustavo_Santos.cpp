#include <bits/stdc++.h>

using namespace std;

int operacao(int i, int v)
{
  if (i == 0)
    return v * 2;
  if (i == 1)
    return v * 3;
  if (i == 2)
    return v / 2;
  if (i == 3)
    return v / 3;
  if (i == 4)
    return v + 7;
  return v - 7;
}

int bfs(int n, int m)
{
  queue<int> q;
  q.push(n);
  map<int, int> dict;
  dict[n] = 0;

  while (!q.empty())
  {
    int v = q.front();
    q.pop();

    for (int i = 0; i < 6; i++)
    {
      int val = operacao(i, v);

      if (dict.find(val) == dict.end())
      {
        dict[val] = dict[v] + 1;
        if (val == m)
          return dict[val];
        q.push(val);
      }
    }
  }

  return dict[m];
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);

  printf("%d\n", bfs(n, m));

  return 0;
}