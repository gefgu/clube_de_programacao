#include <bits/stdc++.h>

using namespace std;

int main()
{
  int gols_gremio, gols_inter;
  int vitorias_inter = 0, vitorias_gremio = 0;
  int empates = 0;

  scanf("%d %d", &gols_inter, &gols_gremio);

  if (gols_inter > gols_gremio)
  {
    vitorias_inter++;
  }
  else if (gols_inter < gols_gremio)
  {
    vitorias_gremio++;
  }
  else
  {
    empates++;
  }

  int continua;

  while (printf("Novo grenal (1-sim 2-nao)\n"),
         scanf("%d", &continua), continua == 1)
  {
    scanf("%d %d", &gols_inter, &gols_gremio);
    if (gols_inter > gols_gremio)
    {
      vitorias_inter++;
    }
    else if (gols_inter < gols_gremio)
    {
      vitorias_gremio++;
    }
    else
    {
      empates++;
    }
  }

  printf("%d grenais\n", vitorias_gremio + vitorias_inter + empates);
  printf("Inter:%d\n", vitorias_inter);
  printf("Gremio:%d\n", vitorias_gremio);
  printf("Empates:%d\n", empates);
  if (vitorias_inter > vitorias_gremio)
  {
    printf("Inter venceu mais\n");
  }
  else if (vitorias_gremio == vitorias_inter)
  {
    printf("Nao houve vencedor\n");
  }
  else
  {
    printf("Gremio venceu mais\n");
  }

  return 0;
}