/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/buggy-bot-d8f6eb53/
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
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)
#define all(c) (c).begin(), (c).end()
#define display(c) \
    forEach(c) { cout << value << endl; }

#define Odd(n) if (n & 1)
#define cases \
    ull t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define deb(x) cout << (#x) << " is " << (x) << endl

using namespace std;

void AddEdge(vec<vi> &graph, int u, int v)
{
    graph[u].eb(v);
}

vec<Pi> gen_error(const ui curr_pos, Pi val, const vec<vi> &graph)
{
    auto nodes = graph[curr_pos];
    ui len = nodes.size();
    vec<Pi> error_path(len);
    ui i;
    loop(i, len - 1)
    {
        ui node = nodes[i];
        if (!(curr_pos == val.first && node == val.second))
        {
            error_path[i] = make_pair(curr_pos, node);
        }
    }
    return error_path;
}

void TraverseToEnd(const vec<Pi> &inst, ui ind, ui currPos, set<ui> &s)
{
    ui e;
    loopab(e, ind, inst.size() - 1, 1)
    {
        if (currPos == inst[e].first)
        {
            currPos = inst[e].second;
        }
    }
    s.insert(currPos);
}

void Reach_to_end(const vec<Pi> &error, ui index, set<ui> &s, const vec<Pi> &inst, ui currPos)
{
    ui j;
    loop(j, error.size() - 1)
    {
        if (currPos = error[j].first)
        {
            currPos = error[j].second;
            TraverseToEnd(inst, index, currPos, s);
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
        ui n, m, k, i;
        cin >> n >> m >> k;
        vec<vi> graph(n, vi());
        loop(i, m - 1)
        {
            ui u, v;
            cin >> u >> v;
            --u;
            --v;
            AddEdge(graph, u, v);
        }
        vec<Pi> inst(k);
        loop(i, k - 1)
        {
            ui start, end;
            cin >> start >> end;
            --start;
            --end;
            inst[i] = make_pair(start, end);
        }

        ui curr_pos = 0;
        set<ui> s;
        // vec<vec<Pi>> error_ins(k + 1, vec<Pi>());
        TraverseToEnd(inst, 0, curr_pos, s);
        loop(i, inst.size() - 1)
        {
            vec<Pi> errorPair = gen_error(curr_pos, inst[i], graph);
            Reach_to_end(errorPair, i, s, inst, curr_pos);
            if (curr_pos == inst[i].first)
            {
                curr_pos = inst[i].second;
            }
        }

        cout << s.size() << endl;
        forEach(s)
        {
            cout << value + 1 << " ";
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
