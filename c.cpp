#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

bool is_num(const string &s)
{
  bool fl = true;
  for (const auto &item : s)
    if (!isdigit(item) && item != '-')
      fl = false;
  return fl;
}

void revert(map<string, int>& mp, stack<pair<string, int>>& history)
{
  while (history.top().first != "-")
  {
    mp.insert_or_assign(history.top().first, history.top().second);
    history.pop();
  }
  history.pop();
}

void parse_block(map<string, int>& mp, stack<pair<string, int>>& history)
{
  string s;
  while (getline(cin, s) && s != "}")
  {
    if (s == "{")
    {
      history.push({"-", 0});
      parse_block(mp, history);
    }
    else
    {
      auto ind = s.find('=');
      auto var = s.substr(0, ind);
      auto right = s.substr(ind + 1, s.length());

      auto it_l = mp.find(var);
      if (it_l == mp.end())
        history.push({var, 0});
      else
        history.push({var, it_l->second});

      if (is_num(right))
        mp.insert_or_assign(var, atoi(right.c_str()));
      else
      {
        auto it = mp.find(right);
        if (it != mp.end())
        {
          mp.insert_or_assign(var, it->second);
          cout << it->second << endl;
        }
        else
        {
          mp.insert_or_assign(var, 0);
          cout << 0 << endl;
        }
      }
    }
  }
  revert(mp, history);
}

int main()
{
  map<string, int> mp;
  stack<pair<string, int>> history;
  history.push({"-", 0});
  parse_block(mp, history);
  return 0;
}
