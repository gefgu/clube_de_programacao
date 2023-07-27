#include <bits/stdc++.h>

using namespace std;

int main()
{
  char a[100], b[100];
  map<string, int> assassinatos;
  map<string, int> mortos;

  while (scanf("%s %s", a, b) != EOF)
  {
    assassinatos[string(a)]++;
    mortos[string(b)] = 1;
  }

  printf("HALL OF MURDERERS\n");
  for (auto &k : assassinatos)
    if (!mortos[k.first])
      printf("%s %d\n", k.first.c_str(), k.second);

  return 0;
}