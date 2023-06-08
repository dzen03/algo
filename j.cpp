#include <iostream>
#include <deque>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie();
  deque<int> left, right;
  int n;
  cin >> n;

  char c;
  int t;

  for (int i = 0; i < n; ++i)
  {
    cin >> c;
    switch (c) 
    {
      case '+':
        cin >> t;
        right.push_back(t);
        break;
      case '-':
        cout << left.front() << endl;
        left.pop_front();
        break;
      case '*':
        cin >> t;
        right.push_front(t);
        break;
    }
    if (left.size() < right.size())
      left.push_back(right.front()), right.pop_front();
  }

  return 0;
}
