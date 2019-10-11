/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/pasha-jumps-on-a-permutation-june-easy-19-9e608b68/
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

void AddEdge(vec<vec<Pi>> &graph, int u, int v, int wt)
{
    graph[u].eb(make_pair(v, wt));
}

int Bfs(vec<vec<Pi>> &graph, int index, int n)
{

    vi minPath(n, INFINITY);
    --n;

    deque<int> q;
    q.push_back(index);
    minPath[index] = 0;
    while (!q.empty())
    {
        int val = q.front();
        q.pop_front();
        int i;
        loop(i, graph[val].size() - 1)
        {

            if (minPath[graph[val][i].first] > minPath[val] + graph[val][i].second)
            {
                minPath[graph[val][i].first] = minPath[val] + graph[val][i].second;
                if (graph[val][i].second == 0)
                {
                    //zero path wt
                    q.push_front(graph[val][i].first);
                }
                else
                {
                    //non zero path wt
                    q.push_back(graph[val][i].first);
                }
            }
            //
            if (!q.empty() && q.front() == n && minPath[n] == 0)
            {
                return minPath[n];
            }
        }
    }

    return minPath[n];
    // return -1;
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
            ui n, i;
            cin >> n;
            vi arr(n);
            vec<vec<Pi>> graph(n, vec<Pi>());
            loop(i, n - 1)
            {
                ui val;
                cin >> val;
                --val;
                if (val != i)
                {
                    AddEdge(graph, i, val, 0);
                }
                if (i > 0)
                    AddEdge(graph, i, i - 1, 1);
                if (i < n - 1)
                    AddEdge(graph, i, i + 1, 1);
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
