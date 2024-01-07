#include <bits/stdc++.h>

#define MAX 112345

using namespace std;
int proibidos[112], dis[MAX];
int o, d, k;

int valid(int canal)
{
  if (canal > 100000 || canal <= 0 || dis[canal] != -1)
    return 0;

  for (int i = 0; i < k; i++)
    if (canal == proibidos[i])
      return 0;

  return 1;
}

int main()
{
  int atual;
  queue<int> q;
  while (scanf("%d %d %d", &o, &d, &k), o != 0 && d != 0)
  {
    int i;
    for (i = 0; i < k; i++)
      scanf("%d", &proibidos[i]);

    for (i = 0; i < MAX; i++)
      dis[i] = -1;

    q.push(o);
    dis[o] = 0;
    atual = o;
    while (!q.empty() && atual != d)
    {
      atual = q.front();
      q.pop();

      if (valid(atual + 1))
      {
        q.push(atual + 1);
        dis[atual + 1] = dis[atual] + 1;
      }
      if (valid(atual - 1))
      {
        q.push(atual - 1);
        dis[atual - 1] = dis[atual] + 1;
      }
      if (valid(atual * 2))
      {
        q.push(atual * 2);
        dis[atual * 2] = dis[atual] + 1;
      }
      if (valid(atual * 3))
      {
        q.push(atual * 3);
        dis[atual * 3] = dis[atual] + 1;
      }
      if (atual % 2 == 0 && valid(atual / 2))
      {
        q.push(atual / 2);
        dis[atual / 2] = dis[atual] + 1;
      }
    }

    printf("%d\n", dis[d]);

    while (!q.empty())
      q.pop();
  }

  return 0;
}