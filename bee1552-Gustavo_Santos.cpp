#include <bits/stdc++.h>

#define MAX 512
#define INF 112345

using namespace std;

typedef pair<int, int> ii;

ii pos[MAX];
float dis[MAX];
int ok[MAX];
int members[MAX];

float distance(ii a, ii b)
{
  return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

float prim(int n)
{

  float ans = 0, minimum;
  int i, j, minimum_index;

  for (i = 0; i < n; i++)
  {
    ok[i] = 0;
    dis[i] = INF;
  }

  dis[0] = 0;
  ok[0] = 1;
  members[0] = 0;

  for (i = 0; i < n - 1; i++)
  {
    minimum = INF;
    for (j = 0; j < n; j++)
    {
      if (ok[j])
        continue;

      float new_dis = distance(pos[members[i]], pos[j]);
      if (dis[j] > new_dis)
        dis[j] = new_dis;
      if (dis[j] < minimum)
      {
        minimum = dis[j];
        minimum_index = j;
      }
    }

    ans += minimum;
    ok[minimum_index] = 1;
    members[i + 1] = minimum_index;
  }

  return ans / 100.0;
}

int main()
{

  int c, n, x, y;

  scanf("%d", &c);

  while (c--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d %d", &x, &y);
      pos[i] = ii(x, y);
    }

    printf("%.2f\n", prim(n));
  }

  return 0;
}