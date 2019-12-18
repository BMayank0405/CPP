/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/just-shortest-distance-problem/
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

int bfs(const vec<vi> &g, int n, vi &p, bool updated, vi &vis)
{

    int curMin = p[n];
    queue<int> q;
    q.push(0);
    bool flag = false;
    if (!updated && p[n] != -1)
    {
        return p[n];
    }
    if (p[n] == 1)
    {

        return p[n];
    }
    while (!q.empty())
    {
        int v = q.front();
        vis[v] = 1;
        q.pop();
        if (flag)
        {
            break;
        }

        for (int i = 0; i < g[v].size(); i++)
        {
            if (curMin == -1)
            {
                if (p[g[v][i]] != -1)
                {
                    if (p[g[v][i]] >= (p[v] + 1))
                    {
                        p[g[v][i]] = 1 + p[v];

                        q.push(g[v][i]);
                    }
                }
                else
                {
                    p[g[v][i]] = 1 + p[v];
                    q.push(g[v][i]);
                }
            }
            else
            {
                if (curMin <= (1 + p[v]))
                {
                    flag = true;
                    break;
                }
                if (p[g[v][i]] != -1)
                {
                    if (p[g[v][i]] >= (p[v] + 1))
                    {
                        p[g[v][i]] = 1 + p[v];
                        if (curMin > p[g[v][i]])
                            q.push(g[v][i]);
                    }
                }
                else
                {
                    p[g[v][i]] = 1 + p[v];
                    if (curMin > p[g[v][i]])
                        q.push(g[v][i]);
                }
            }
            if (g[v][i] == n)
            {
                flag = true;
                break;
            };
        }
    }
    return p[n];
}

int bfsFromQueue(const vec<vec<Pi>> &g, int n, vi &p, bool updated, vi &visited, queue<int> &q)
{
    int curMin = p[n];
    bool flag = false;

    //update graph first untill n is found and then visit form last path updated node

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        int n, m;
        cin >> n >> m;
        vi visited(n, 0);
        vec<vec<Pi>> g(n, vec<Pi>());
        queue<int> q;
        vi p(n + 1, -1);
        p[0] = 0;
        bool updated = false;

        while (m--)
        {
            int q, u, v;
            cin >> q >> u;
            --u;
            if (q == 1)
            {
                if (u == 0 || g[0].empty() || p[u] == 1)
                {
                    cout << p[u] << endl;
                }
                else
                {
                    cout << bfsFromQueue(g, );
                }
                updated = false;
            }

            if (q == 2)
            {
                updated = true;
                cin >> v;
                --v;
                visited[v] = 0;
                if (u != v && p[v] > 1)
                {

                    g[u].eb(v);
                    // g[v].eb(u);
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
