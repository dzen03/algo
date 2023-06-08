#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  string s;
  string ans;
  stack<pair<char, int>> st;
  cin >> s;
  int id_l = 0, id_u = 0;
  vector<int> ids(s.length(), -1);
  for (auto el: s)
  {
    if (islower(el))
    {
      ++id_l;
    }
    else
    {
      ++id_u;
    }
    if (!st.empty() && tolower(st.top().first) == tolower(el) && st.top().first != el)
    {
      if (islower(el))
        ids[st.top().second - 1] = id_l;
      else
        ids[id_u - 1] = st.top().second;
      st.pop();
    }
    else
      if (isupper(el))
        st.push({el, id_u});
      else
        st.push({el, id_l});
  }

  if (st.empty())
  {
    cout << "Possible" << endl;
    for (auto el: ids)
    {
      if (el == -1)
        break;
      cout << el << " ";
    }
  }
  else
    cout << "Impossible" << endl;
  return 0;
}
