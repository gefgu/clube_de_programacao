#include <bits/stdc++.h>

using namespace std;

#define MAX 11234567

int prox[MAX];
int vis[MAX];
int dis[MAX];

int dfs(int a)
{
  // printf("%d\n", a);
  if (dis[a] != 0)
    return dis[a];
  vis[a]++;
  if (vis[a] > 1)
    return MAX;
  if (prox[a] == -1)
  {
    dis[a] = 1;
    return 1;
  }
  dis[a] = dfs(prox[a]) + 1;
  return dis[a];
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  int i;

  for (i = 0; i < MAX; i++)
  {
    prox[i] = 0;
    vis[i] = 0;
    dis[i] = 0;
  }

  for (i = 1; i <= n; i++)
  {
    if (i % 2 == 0)
      prox[i] = i / 2;
    else if ((i * 3 + 1) <= n)
      prox[i] = (i * 3) + 1;
    else
      prox[i] = -1;
  }

  for (i = 1; i <= n; i++)
    dfs(i);

  int pos = 0;

  for (i = 1; i <= n; i++)
  {
    if (dis[i] >= k)
      pos++;
  }

  printf("%d\n", pos);

  return 0;
}