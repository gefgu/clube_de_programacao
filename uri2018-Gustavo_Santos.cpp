#include <bits/stdc++.h>

using namespace std;

// 2 greater
// 1 equal
// 0 less
int compare(int a[3], int b[3])
{
  int ans = 2;
  if (a[0] < b[0])
    ans = 0;
  else if (a[0] == b[0])
  {
    if (a[1] < b[1])
      ans = 0;
    else if (a[1] == b[1])
    {
      if (a[2] < b[2])
        ans = 0;
      else if (a[2] == b[2])
        ans = 1;
    }
  }

  return ans;
}

int main()
{
  map<string, int[3]> country_to_medals;
  int i, j, k;
  string s;
  vector<string> countries;

  while (getline(cin, s), !cin.eof())
  {
    for (i = 0; i < 3; i++)
    {
      getline(cin, s);
      country_to_medals[s][i]++;
    }
  }

  for (auto &a : country_to_medals)
    countries.push_back(a.first);

  for (i = 1; i < (int)countries.size(); i++)
  {
    s = countries[i];
    j = i - 1;
    while (k = compare(country_to_medals[s], country_to_medals[countries[j]]),
           j > -1 && (k == 2 || (k == 1 && s.compare(countries[j]) < 0)))
    {
      countries[j + 1] = countries[j];
      j--;
    }
    countries[j + 1] = s;
  }

  printf("Quadro de Medalhas\n");
  for (auto &a : countries)
  {
    printf("%s %d %d %d\n", a.c_str(), country_to_medals[a][0], country_to_medals[a][1], country_to_medals[a][2]);
  }

  return 0;
}