/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-learning-graph-3/
 */

#include <bits/stdc++.h>

//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define uns unsigned
#define usi uns short int //
#define ui uns int
#define ull uns long long
#define power9 (int)(1e9 + 7)
#define totalChars 25
#define Pi pair<int, int>
#define Punsi pair<ui, ui>
#define vec vector
#define vi vec<int>
#define vui vec<ui>
#define vll vec<ll>
#define vull vec<ull>
#define endl "\n";
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)
#define all(c) (c).begin(), (c).end()
#define display(c) \
    forEach(c) { cout << c << endl; }

#define Odd(n) if (n & 1)
#define cases \
    ull t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define deb(x) cout << (#x) << " is " << (x) << endl

using namespace std;

bool customSort(const pair<int, int> &a,
                const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return (a.second < b.second);
    }
    return (a.first < b.first);
}

void AddEdge(vec<vi> &tree, int u, int v)
{
    tree[u].eb(v);
    tree[v].eb(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        //write your code here
        int n, m, k, i;
        cin >> n >> m >> k;
        vec<Pi> arr(n), sorted(n);
        vec<vi> tree(n, vi());
        vi ind(n);
        loop(i, n - 1)
        {
            int g;
            cin >> g;
            arr[i] = make_pair(g, i);
            sorted[i] = arr[i];
        }
        sort(all(sorted)); //nlogn

        loop(i, n - 1)
        {
            ind[sorted[i].second] = i;
        }

        loop(i, m - 1)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            AddEdge(tree, u, v);
        }

        forEach(tree)
        {
            vi boolind(n, 0);
            loop(i, value.size() - 1)
            {
                boolind[ind[value[i]]] = 1;
            }
            Pi m;
            int p = k;
            for (i = boolind.size() - 1; i >= 0; --i)
            {
                if (p == 0)
                    break;
                else
                {
                    if (boolind[i] == 1)
                    {
                        m = sorted[i];
                        --p;
                    }
                }
            }

            cout << m.second + 1 << endl;
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
