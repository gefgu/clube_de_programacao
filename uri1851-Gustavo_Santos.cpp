#include <bits/stdc++.h>

using namespace std;

// Ideia: Escolha com maior "custo benefício" para ser treinado: multa / dias
// A multa é o "benefício" e a quantidade de dias, o "custo"

#define MAX 112345

typedef pair<int, int> ii;
typedef pair<float, int> fi;
typedef long long ll;

int main()
{
  ii dias_multas[MAX];
  int n = 0;
  ll dia = 0, proximo_dia = 0, multa_do_dia = 0, multa = 0;
  priority_queue<fi, vector<fi>, less<fi>> q;

  while (scanf("%d %d", &dias_multas[n].first, &dias_multas[n].second) != EOF)
    n++;

  for (dia = 0; dia < n || !q.empty(); dia++)
  {
    if (dia < n)
    {
      q.push(fi(dias_multas[dia].second / (float)dias_multas[dia].first, dia));
      multa_do_dia += dias_multas[dia].second;
    }

    if (dia == proximo_dia && !q.empty())
    {
      proximo_dia += dias_multas[q.top().second].first;
      multa_do_dia -= dias_multas[q.top().second].second;
      q.pop();
    }

    multa += multa_do_dia;
  }

  printf("%lld\n", multa);
}