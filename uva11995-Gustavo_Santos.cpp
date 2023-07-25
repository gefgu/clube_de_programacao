#include <bits/stdc++.h>

using namespace std;

int main()
{
  stack<int> s;
  queue<int> q;
  priority_queue<int, vector<int>, less<int>> pq;
  int eh_stack, eh_queue, eh_priority;
  int n, action, x;

  while (scanf("%d", &n) != EOF)
  {
    eh_stack = 1;
    eh_queue = 1;
    eh_priority = 1;
    while (n--)
    {
      scanf("%d %d", &action, &x);

      if (action == 1)
      {
        s.push(x);
        q.push(x);
        pq.push(x);
      }

      if (action == 2 && !s.empty())
      {
        if (x != s.top())
          eh_stack = 0;
        if (x != q.front())
          eh_queue = 0;
        if (x != pq.top())
          eh_priority = 0;

        s.pop();
        q.pop();
        pq.pop();
      }
      else if (action == 2)
      {
        eh_stack = 0;
        eh_queue = 0;
        eh_priority = 0;
      }
    }

    while (!s.empty())
      s.pop();
    while (!q.empty())
      q.pop();
    while (!pq.empty())
      pq.pop();

    if (eh_stack + eh_queue + eh_priority >= 2)
      printf("not sure\n");
    else if (eh_stack + eh_queue + eh_priority == 0)
      printf("impossible\n");
    else if (eh_stack)
      printf("stack\n");
    else if (eh_queue)
      printf("queue\n");
    else if (eh_priority)
      printf("priority queue\n");
  }

  return 0;
}