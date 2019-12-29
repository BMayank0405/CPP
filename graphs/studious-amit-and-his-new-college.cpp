/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/studious-amit-and-his-new-college/
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

void addEdge(vec<vui> &graph, ui u, ui v)
{
    graph[u].eb(v);
}

bool hasCycle(vec<vui> &graph, vui &vis, ui s, vui &recStack)
{
    vis[s] = 1;
    recStack[s] = 1;
    for (int i = 0; i < graph[s].size(); i++)
    {
        if (vis[graph[s][i]] == 0 && hasCycle(graph, vis, graph[s][i], recStack))
            return true;
        else if (recStack[graph[s][i]])
            return true;
    }
    recStack[s] = 0;
    return false;
}

bool isCyclic(vec<vui> &graph, ui n)
{
    ui i;
    vui vis(n, 0);
    vui recStack(n, 0);
    bool cycle = false;
    loop(i, n - 1)
    {
        if (vis[i] == 0 && hasCycle(graph, vis, i, recStack))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        //write your code here

        cases
        {
            ui n, m, i;
            cin >> n >> m;
            vec<vui> graph(n, vui());
            loop(i, m - 1)
            {
                ui u, v;
                cin >> u >> v;
                --u, --v;
                addEdge(graph, u, v);
            }
            if (m == 0)
            {
                cout << 1 << endl;
            }
            else
            {

                if (isCyclic(graph, n))
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << 1 << endl;
                }
            }
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
