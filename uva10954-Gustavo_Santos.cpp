#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, i, a, b, cost;
  priority_queue<int, vector<int>, greater<int>> q;

  while (scanf("%d", &n), n != 0)
  {
    cost = 0;
    for (i = 0; i < n; i++)
    {
      scanf("%d", &a);
      q.push(a);
    }
    while (!q.empty())
    {
      a = q.top();
      q.pop();
      b = q.top();
      q.pop();
      cost += a + b;
      if ((int)q.size() > 0)
        q.push(a + b);
    }

    printf("%d\n", cost);
  }
}