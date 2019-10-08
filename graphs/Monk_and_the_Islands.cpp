/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
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

int Bfs(vec<vi> &graph, int index, int n)
{
    vec<bool> vis(n, false);
    vi minPath(n, 0);
    --n;
    int count = 0;

    if (index != n)
    {

        queue<Pi> q;
        q.push(make_pair(-1, index));
        vis[index] = true;
        while (!q.empty())
        {
            Pi ind = q.front();
            q.pop();
            int i;
            int val = ind.second;
            loop(i, graph[val].size() - 1)
            {
                if (graph[val][i] == n)
                {
                    count = minPath[val] + 1;
                    return count;
                }
                else if (!vis[graph[val][i]])
                {
                    vis[graph[val][i]] = true;
                    minPath[graph[val][i]] = minPath[val] + 1;
                    q.push(make_pair(val, graph[val][i]));
                }
            }
        }
    }
    return count;
}

void AddEdge(vec<vi> &graph)
{
    ui u, v;
    cin >> u >> v;
    --u;
    --v;
    graph[u].eb(v);
    graph[v].eb(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        cases
        {

            ui n, m, k, i;
            cin >> n >> m;
            vec<vi> graph(n, vi());

            loop(i, m - 1)
            {
                AddEdge(graph);
            }
            cout << Bfs(graph, 0, n) << endl;
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
