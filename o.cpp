#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, int prev_color, const vector<vector<int>>& arr, vector<int>& color)
{
  color[v] = -(prev_color - 3);
  for (auto el: arr[v])
    if (color[el] == 0)
      dfs(el, color[v], arr, color);
    else if (prev_color != color[el])
    {
      cout << "NO";
      exit(0);
    }

}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n);
  vector<int> color(n);

  int t1, t2;

  for (int i = 0; i < m; ++i)
  {
    cin >> t1 >> t2;
    arr[t1 - 1].push_back(t2 - 1);
    arr[t2 - 1].push_back(t1 - 1);
  }

  for (int i = 0; i < n; ++i)
    if (color[i] == 0)
      dfs(i, 1, arr, color);

  cout << "YES";

  return 0;
}
