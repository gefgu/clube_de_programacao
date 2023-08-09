#include <bits/stdc++.h>

using namespace std;

#define MAX 112345

typedef long long ll;

ll seg[4 * MAX], lazy[4 * MAX];
int n;

ll _get(int p, int l, int r, int i, int j)
{
  if (j < l || i > r)
    return 0;

  if (lazy[p] != 0)
  {
    seg[p] += (r - l + 1) * lazy[p];
    if (l != r)
    {
      lazy[p * 2] += lazy[p];
      lazy[p * 2 + 1] += lazy[p];
    }
    lazy[p] = 0;
  }

  if (i <= l && r <= j)
    return seg[p];

  int mid = (l + r) / 2;

  return _get(p * 2, l, mid, i, j) + _get((p * 2) + 1, mid + 1, r, i, j);
}

void _update(int p, int l, int r, int i, int j, ll val)
{
  if (lazy[p] != 0)
  {
    seg[p] += (r - l + 1) * lazy[p];
    if (l != r)
    {
      lazy[p * 2] += lazy[p];
      lazy[p * 2 + 1] += lazy[p];
    }
    lazy[p] = 0;
  }

  if (j < l || i > r)
    return;
  if (i <= l && r <= j)
  {
    seg[p] += (r - l + 1) * val;
    if (l != r)
    {
      lazy[p * 2] += val;
      lazy[p * 2 + 1] += val;
    }
    return;
  }

  int mid = (l + r) / 2;
  _update(p * 2, l, mid, i, j, val);
  _update(p * 2 + 1, mid + 1, r, i, j, val);
  seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

int main()
{
  int t, c, action, p, q, v;

  scanf("%d", &t);

  while (t--)
  {
    memset(seg, 0, sizeof(seg));
    memset(lazy, 0, sizeof(lazy));
    scanf("%d %d", &n, &c);
    while (c--)
    {
      scanf("%d %d %d", &action, &p, &q);
      p--;
      q--;
      if (p > q)
        swap(p, q);
      if (action == 0)
      {
        scanf("%d", &v);
        _update(1, 0, n - 1, p, q, v);
      }
      else if (action == 1)
      {
        printf("%lld\n", _get(1, 0, n - 1, p, q));
      }
    }
  }

  return 0;
}