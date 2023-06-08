#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <stack>

using namespace std;

#define inf (int)1e9
//#define getPrice(x) ((x) == '.' ? 1 : ((x) == 'W' ? 2 : inf))
//#define int long long




template <class T>
class queues
{
 private:
  vector<queue<T>> q;
  size_t cnt;
  size_t length;
 public:
  explicit queues(int n)
  {
    q.resize(n);
    cnt = 0;
    length = 0;
  }

  void push(T x, int n)
  {
    q[(cnt + n) % q.size()].push(x);
    ++length;
  }

  T pop()
  {
    while (q[cnt].size() == 0)
      cnt = (cnt + 1) % q.size();
    T res = q[cnt].front();
    q[cnt].pop();
    --length;
    return res;
  }

  size_t size()
  {
    return length;
  }
};


int n, m;

struct point
{
  int x;
  int y;
  pair<int, int> parent;

  bool is_valid()
  {
    return (x >= 0 && x < n && y >= 0 && y < m);
  }

  pair<bool, const point> move(pair<int, int> a)
  {
    auto res = point({x + a.first, y + a.second, {-a.first, -a.second}});
    return {res.is_valid(), res};
  }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie();
  cin >> n >> m;
  pair<int, int> start, finish;
  cin >> start.first >> start.second;
  cin >> finish.first >> finish.second;

  start = {start.first - 1, start.second - 1};
  finish = {finish.first - 1, finish.second - 1};

  vector<vector<int>> arr(n, vector<int> (m));
  queues<point> q(3);

  vector<vector<pair<int, int>>> path(n, vector<pair<int, int>> (m, {0, 0}));

  char inp;
  for (auto& row: arr)
    for (auto& el: row)
    {
      cin >> inp;
      switch (inp)
      {
        case '.':
          el = 1;
          break;
        case 'W':
          el = 2;
          break;
        case '#':
          el = 0;
          break;
      }
    }

  int cnt = 0;
  q.push({start.first, start.second, {-1, -1}}, 0);

  vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (q.size() > 0)
  {
    point t = q.pop();



    if (path[t.x][t.y] == make_pair(0, 0))
      path[t.x][t.y] = t.parent;
    else
      continue;


    for (auto& move: moves)
    {
      auto tmp = t.move(move);
      if (tmp.first && path[tmp.second.x][tmp.second.y] == make_pair(0, 0) && arr[tmp.second.x][tmp.second.y])
      {
        q.push(tmp.second, arr[tmp.second.x][tmp.second.y]);
//        path[tmp.second.x][tmp.second.y] = tmp.second.parent;
      }
    }

//    for (auto& row: path)
//    {
//      for (auto& el: row)
//        cout << el.first << el.second << "\t\t\t";
//      cout << endl;
//    }
//    cout << endl;
  }

  point current({finish.first, finish.second});

  int ans1 = 0;
  stack<char> ans2;

  if (path[current.x][current.y] == make_pair(0, 0))
  {
    cout << -1;
    return 0;
  }

  while (path[current.x][current.y] != make_pair(-1, -1))
  {
    auto dir = path[current.x][current.y];
    ans1 += arr[current.x][current.y];

    if (dir.first == -1)
      ans2.push('S');
    else if (dir.first == 1)
      ans2.push('N');
    else if (dir.second == -1)
      ans2.push('E');
    else if (dir.second == 1)
      ans2.push('W');

    current = current.move(path[current.x][current.y]).second;
  }


  cout << ans1 << endl;

  while (!ans2.empty())
    cout << ans2.top(), ans2.pop();

  return 0;
}
