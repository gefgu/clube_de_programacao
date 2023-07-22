#include <bits/stdc++.h>

using namespace std;

#define MAX 51234 // Um pouco mais do que sqrt(2^31)

typedef long long ll;

int p[MAX], pi;

void sieve()
{
  int i, j, prime, r;

  p[0] = 2;
  pi = 1;
  for (i = 3; i < MAX; i++)
  {
    prime = 1;
    r = sqrt(i);
    for (j = 0; j < pi && prime && p[j] <= r; j++)
      if (i % p[j] == 0)
        prime = 0;

    if (prime)
      p[pi++] = i;
  }
}

// Calcula o expoente do fator primo f na decomposicao de n!
int multsInFactorial(int n, int f)
{
  int n_mults = 0;
  ll power = f;
  while (power <= n)
  {
    n_mults += n / power;
    power *= f;
  }
  return n_mults;
}

// Fatora m e checa se m divide n
int divide(int n, int m)
{
  int m_factors[MAX], m_mults[MAX], k = 0, i, flag = 1;

  if (m <= n)
    return 1;

  for (i = 0; i < pi && p[i] * p[i] <= m; i++)
    if (m % p[i] == 0)
    {
      m_mults[k] = 0;
      while (m % p[i] == 0)
      {
        m /= p[i];
        m_mults[k]++;
      }
      m_factors[k++] = p[i];
    }

  if (m > 1)
  {
    m_factors[k] = m;
    m_mults[k++] = 1;
  }

  for (i = 0; i < k && flag; i++)
    if (multsInFactorial(n, m_factors[i]) < m_mults[i])
      flag = 0;

  return flag;
}

int main()
{
  int n, m;

  sieve();

  while (scanf("%d %d", &n, &m) != EOF)
  {
    printf("%d %s %d!\n", m, divide(n, m) ? "divides" : "does not divide", n);
  }

  return 0;
}