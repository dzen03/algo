#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    multimap<int, int> free; // size, start
    map<int, int> used; // start, size
    map<int, int> free_rev; // start, size // TODO consider moving to std::set

    int n, m;
    int inp;

    cin >> n >> m;

    vector<int> hist(m, -1);

    free.insert({n, 1});
    free_rev.insert({1, n});

    for (int i = 0; i < m; ++i)
    {
        cin >> inp;
        if (inp > 0) // allocate
        {
            auto pl = free.lower_bound(inp);
            auto size = pl->first, start = pl->second;
            if (pl != free.end())
            {
                free.erase(pl);
                free_rev.erase(start);

                if (size > inp)
                {
                    free.insert({size - inp, start + inp});
                    free_rev.insert({start + inp, size - inp});
                }

                used.insert({start, inp});
                hist[i] = start;

                cout << start << endl;
            }
            else
                cout << -1 << endl;
        }
        else // free
        {
            inp *= -1;

            int start = hist[inp - 1];

            if (start == -1)
                continue;

            auto it = used.find(start);
            int end = start + it->second - 1;
            used.erase(it);


            auto next = free_rev.lower_bound(start);
            bool has_prev = (next != free_rev.begin());
            auto prev = free_rev.lower_bound(start);

            if (has_prev)
                --prev;

            if (*next != *free_rev.end() && next->first == end + 1)
            {
                end += next->second;
                auto range = free.equal_range(next->second);
                for (auto it = range.first; it != range.second; ++it)
                    if (it->second == next->first)
                    {
                        free.erase(it);
                        break;
                    }
                free_rev.erase(next);
            }

            if (has_prev && prev->first + prev->second == start)
            {
                start = prev->first;
                auto range = free.equal_range(prev->second);
                for (auto it = range.first; it != range.second; ++it)
                    if (it->second == prev->first)
                    {
                        free.erase(it);
                        break;
                    }
                free_rev.erase(prev);
            }

            free.insert({end - start + 1, start});
            free_rev.insert({start, end - start + 1});
        }
    }

    return 0;
}
