#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

stack<int> d1;

#define INF 1e9

void dfs1(int v, vector<bool>& used,  const vector<vector<int>>& arr, int lim)
{
  used[v] = true;
  for (int i = 0; i < arr[v].size(); ++i)
    if (!used[i] && arr[v][i] < lim)
      dfs1(i, used, arr, lim);
  d1.push(v);
}

void dfs2(int v, vector<bool>& used,  const vector<vector<int>>& arr, int lim)
{
  used[v] = true;
  for (int i = 0; i < arr[v].size(); ++i)
    if (!used[i] && arr[i][v] < lim)
      dfs2(i, used, arr, lim);
}


int main()
{
  int n;
  cin >> n;

  vector<vector<int>> arr(n, vector<int> (n));
  set<pair<int, pair<int, int>>> list;



  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    {
      cin >> arr[i][j];
    }

  int l = 0, r = 1e9;

  vector<bool> used(n);

  used.assign(n, false);
  for (int i = 0; i < n; ++i)
    if (!used[i])
      dfs1(i, used, arr, 1e9);

  int norm = 0;
  used.assign(n, false);
  for (int i = 0; i < n; ++i)
  {
    int tmp = d1.top();
    d1.pop();
    if (!used[tmp])
    {
      ++norm;
      dfs2(tmp, used, arr, 1e9);
    }
  }

  while (r - l > 1)
  {
    int m = (r + l) / 2;
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
      if (!used[i])
        dfs1(i, used, arr, m);

    int ans = 0;
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
      int tmp = d1.top();
      d1.pop();
      if (!used[tmp])
      {
        ++ans;
        dfs2(tmp, used, arr, m);
      }
    }
    if (ans != norm)
      l = m;
    else
      r = m;
  }

  cout << l;
  return 0;
}
