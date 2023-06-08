#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie();
  int n, k, t;
  cin >> n >> k;
  multiset<int> s;
  queue<int> a;
  for (int i = 0; i < k; ++i)
  {
    cin >> t;
    s.insert(t);
    a.push(t);
  }
  for (int i = k; i < n; ++i)
  {
    cin >> t;
    a.push(t);
    cout << *s.begin() << " ";
    s.erase(s.find(a.front()));
    a.pop();
    s.insert(t);
  }
  cout << *s.begin();
  return 0;
}
