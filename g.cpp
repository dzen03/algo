#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string s;
  cin >> s;
  vector<pair<int, char>> arr(26);
  for (char i = 0; i < 26; ++i)
    cin >> arr[i].first, arr[i].second = i + 'a';

  string good, mid;

  vector<int> cnt(256, 0);

  for (auto& c: s)
    ++cnt[c];

  sort(arr.rbegin(), arr.rend());

  for(auto& chr: arr)
  {
    if(cnt[chr.second] >= 2)
    {
      good.push_back(chr.second);
      for (int i = 2; i < cnt[chr.second]; ++i)
        mid.push_back(chr.second);
    }
    else if (cnt[chr.second] > 0)
    {
      mid.push_back(chr.second);
    }
  }

  cout << good << mid << string(good.rbegin(), good.rend());

  return 0;
}
