/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
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
#define Pui pair<ui, ui>
#define vec vector
#define vi vec<int>
#define vui vec<ui>
#define vll vec<ll>
#define vull vec<ull>
#define endl "\n";
#define mp make_pair;
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

void addEdge(vec<vi> &graph, int u, int v)
{
    graph[u].eb(v);
    graph[v].eb(u);
}

void dfs(int s, vi &vis, vec<vi> &graph, vi &minDist)
{
    vis[s] = 1;

    for (int i = 0; i < graph[s].size(); i++)
    {
        if (vis[graph[s][i]] == 0)
        {
            minDist[graph[s][i]] = 1 + minDist[s];
            dfs(graph[s][i], vis, graph, minDist);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        int n, i;
        cin >> n;
        vec<vi> graph(n, vi());
        vi vis(n, 0);
        vi minDist(n, -1);
        minDist[0] = 0;
        loop(i, n - 2)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            addEdge(graph, u, v);
        }
        dfs(0, vis, graph, minDist);
        int q;
        cin >> q;
        int min = 100000, minId = 10000;
        loop(i, q - 1)
        {
            int g;
            cin >> g;
            --g;
            if (min > minDist[g])
            {
                min = minDist[g];
                minId = g;
            }
            else if (min == minDist[g])
            {
                if (minId > g)
                {
                    min = minDist[g];
                    minId = g;
                }
            }
        }
        cout << ++minId;
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
