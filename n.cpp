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
}

void dfs2(int v, vector<bool>& used,  const vector<vector<int>>& arr, int lim)
{
  used[v] = true;
  for (int i = 0; i < arr[v].size(); ++i)
    if (!used[i] && arr[i][v] < lim)
    {

      dfs2(i, used, arr, lim);
      dfs1(i, used, arr, lim);

    }
}


int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int> (n, INF));
  set<pair<int, pair<int, int>>> list;



  int tmp;
  for (int i = 0; i < n; ++i)
  {
    cin >> tmp;
    arr[tmp - 1][i] = 1;
  }

  int l = 0, r = 1e9;

  vector<bool> used(n);
  int ans = 0;

  used.assign(n, false);
  for (int i = 0; i < n; ++i)
    if (!used[i])
    {
      dfs1(i, used, arr, 1e9);
      dfs2(i, used, arr, 1e9);
      ++ans;
    }

  cout << ans;
  return 0;
}
