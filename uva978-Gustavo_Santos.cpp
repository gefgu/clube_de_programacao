#include <bits/stdc++.h>

using namespace std;

int main()
{

  int ncases, battlefields, glem, blem, i, ngreens, nblues, nfights;
  priority_queue<int, vector<int>, less<int>> greens, blues;
  queue<int> waiting_greens, waiting_blues;

  scanf("%d", &ncases);

  while (ncases--)
  {
    scanf("%d %d %d", &battlefields, &ngreens, &nblues);
    for (i = 0; i < ngreens; i++)
    {
      scanf("%d", &glem);
      greens.push(glem);
    }
    for (i = 0; i < nblues; i++)
    {
      scanf("%d", &blem);
      blues.push(blem);
    }

    while (!greens.empty() && !blues.empty())
    {
      // Fights
      nfights = min(battlefields, min((int)greens.size(), (int)blues.size()));
      for (i = 0; i < nfights; i++)
      {
        glem = greens.top();
        greens.pop();
        blem = blues.top();
        blues.pop();

        if (glem > blem)
          waiting_greens.push(glem - blem);
        else if (glem < blem)
          waiting_blues.push(blem - glem);
      }

      // Replacements
      while (!waiting_greens.empty())
      {
        greens.push(waiting_greens.front());
        waiting_greens.pop();
      }

      while (!waiting_blues.empty())
      {
        blues.push(waiting_blues.front());
        waiting_blues.pop();
      }
    }

    if (greens.empty() && blues.empty())
    {
      printf("green and blue died\n");
    }
    else if (!greens.empty() && blues.empty())
    {
      printf("green wins\n");
      while (!greens.empty())
      {
        printf("%d\n", greens.top());
        greens.pop();
      }
    }
    else
    {
      printf("blue wins\n");
      while (!blues.empty())
      {
        printf("%d\n", blues.top());
        blues.pop();
      }
    }

    if (ncases > 0)
      printf("\n");
  }

  return 0;
}