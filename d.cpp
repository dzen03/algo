#include<iostream>
#define $ std::
int main()
{
  int a, b, c, d, k, f;
  $ cin >> a >> b >> c >> d >> k;
  for (int i = 0; i < k; ++i)
  {
    f = a, a = $ max(0, $ min(a*b - c,d));
    if (a == f || a == 0)
        break;
  }
  $ cout << a;
}