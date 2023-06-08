#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& el: a)
    cin >> el;

  sort(a.rbegin(), a.rend());

  int ans = 0;

  for (int i = 1; i <= n; ++i)
  {
    if (i % k != 0)
      ans += a[i - 1];
  }

  cout << ans;
  return 0;
}
