#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string s;
  vector<string> arr;
  for (;cin >> s; arr.push_back(s));

  sort(arr.begin(), arr.end(), [](const string& a, const string& b){
    return ("1" + a + b) > ("1" + b + a);
  });

  for (const string& a: arr)
    cout << a;
  return 0;
}
