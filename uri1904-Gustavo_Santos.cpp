#include <bits/stdc++.h>

using namespace std;

#define MAX 11234567

typedef long long ll;

int p[MAX], pi;

void sieve()
{
  int i, j, r, prime;

  pi = 0;
  p[pi++] = 2;
  for (i = 3; i < MAX; i++)
  {
    prime = 1;
    r = sqrt(i);
    for (j = 0; j < pi && p[j] <= r && prime; j++)
      if (i % p[j] == 0)
        prime = 0;

    if (prime)
      p[pi++] = i;
  }
}

// Calcula número de primos entre [a, b]
int nPrimesInRange(int a, int b)
{
  int i, qty = 0;
  for (i = 0; i < pi && p[i] <= b; i++)
    if (p[i] >= a)
      qty++;
  return qty;
}

ll nExpoentes(int n, int p)
{
  int expoentes = 0;
  ll power = p;
  while (n >= power)
  {
    expoentes += n / power;
    power *= p;
  }
  return expoentes;
}

int combinationIsEven(int n, int k)
{
  int powersOfTwo = nExpoentes(n, 2);
  powersOfTwo -= nExpoentes(n - k, 2);
  powersOfTwo -= nExpoentes(k, 2);
  return powersOfTwo >= 1;
}

int main()
{

  int a, b, n, roundsIsEven, diff;

  sieve();

  scanf("%d %d", &a, &b);
  if (b > a)
    swap(a, b);

  diff = a - b;
  if (diff == 0)
  {
    printf("?\n");
  }
  else
  {
    n = nPrimesInRange(b, a); // b é menor que a

    roundsIsEven = combinationIsEven(n + diff - 1, diff);
    printf("%s\n", (roundsIsEven || n == 0) ? "Bob" : "Alice");
  }

  return 0;
}