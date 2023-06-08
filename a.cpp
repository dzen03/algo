#include <iostream>

using namespace std;

signed main()
{
  int n;
  cin >> n;
  if (n < 3)
  {
    cout << 1 << " " << n << endl;
    return 0;
  }
  int len = 0, max_len = -1;
  int prev_color = -1, len_same = 0, color;
  int begin_photo = -1, end_photo = -1;
  for (int i = 0; i < n; ++i)
  {
    cin >> color;
    ++len;
    if (color == prev_color)
    {
      ++len_same;
      if (len_same == 3)
      {
        len_same = 2;
        if (len - 1 > max_len)
        {
          begin_photo = i - len + 1;
          end_photo = i - 1;
          max_len = len - 1;
        }
        len = 2;
      }
    }
    else
    {
      len_same = 1;
    }
    prev_color = color;
  }

  if (len > max_len)
  {
    begin_photo = n - len;
    end_photo = n - 1;
  }

  cout << begin_photo + 1 << " " << end_photo + 1 << endl;

  return 0;
}

/*
5
1 2 3 3 3

 */