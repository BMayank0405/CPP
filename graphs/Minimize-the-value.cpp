/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/minimize-the-magic-05a3986c/
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

void addEdge(vec<vull> &graph, ull u, ull v)
{
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
        //write your code here
        ull n, x, i;
        ull sum = 0;
        cin >> n >> x;
        ++n;
        vec<vull> graph(n, vull());
        vull val(n, 0), vis(n, 0), h(n, 0);
        loop(i, n - 2)
        {
            cin >> val[i];
        }
        val[n - 1] = x;
        loop(i, n - 3)
        {
            ull u, v;
            cin >> u >> v;
            --u;
            --v;
            addEdge(graph, u, v);
        }

        //bfs for tree
        queue<ull> q;
        bool addedNewNode = false;
        h[0] = 1;
        q.push(0);

        while (!q.empty())
        {
            ull v = q.front();
            vis[v] = 1;

            q.pop();
            sum += (h[v] * val[v]);
            if (!addedNewNode && graph[v].size() < 2)
            {
                addEdge(graph, v, n - 1);
                addedNewNode = true;
            }
            if (graph[v].size() > 0)
            {

                loop(i, graph[v].size() - 1)
                {

                    if (vis[graph[v][i]] == 0)
                    {
                        h[graph[v][i]] = h[v] + 1;

                        q.push(graph[v][i]);
                    }
                }
            }
        }
        cout << sum;
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
