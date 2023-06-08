#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie();
  int n, k, p, ans = 0;
  cin >> n >> k >> p;


  vector<int> next_num(p);
  vector<int> seq(p);

  set<int> floor;
  set<pair<int, int>> nums;

  for (auto& el : seq)
      cin >> el, --el;

  vector<int> temp(n, 1e9);

  for (int i = p - 1; i >= 0; --i)
  {
      next_num[i] = temp[seq[i]];
      temp[seq[i]] = i;
  }

  for (int i = 0; i < p; ++i)
  {
      if (floor.find(seq[i]) != floor.end())
      {
          nums.erase({i, seq[i]});
          nums.insert({next_num[i], seq[i]});
          continue;
      }

      if(floor.size() == k)
      {
          auto car_to_del = *nums.rbegin();
          floor.erase(car_to_del.second);
          nums.erase(car_to_del);
      }

      floor.insert(seq[i]);
      nums.insert({next_num[i], seq[i]});
      ++ans;
  }

  cout << ans;
  return 0;
}
