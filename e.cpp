#include<iostream>
#include<vector>

using namespace std;

bool try_place(int len, vector<int>& a, int k)
{
    int prev = a[0];
    int cows = 1;
    for (int i = 1; i < a.size(); ++i)
    {
        if (a[i] - prev >= len)
        {
            prev = a[i];
            ++cows;
        }
    }
    return (cows >= k);
}

int main()
{
    int l = 0, r = 1e9, m;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto& el: a)
        cin >> el;

    while (r - l > 1)
    {
        m = (r + l) / 2;
        if (try_place(m, a, k))
            l = m;
        else
            r = m;
    }

    cout << l;

    return 0;
}