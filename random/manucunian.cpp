/*
 * author: bmayank
 */

#include <bits/stdc++.h>

//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define ull unsigned long long
#define MOD unsigned int modulus = 1e9 + 7
#define P pair<int, int>
//end of shorten coding time

//helper code
#define frlp(c) for (const auto &value : c)
#define REP(n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define Odd(n) if (n & 1)
#define cases \
    int t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
vector<int> graph[100001];
bool to_delete[100001];
int p[100001];
int ans = 0;

void dfs(int node)
{
    if (to_delete[node] == 1)
    {
        ++ans;
        return;
    }
    for (int i : graph[node])
    {
        dfs(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    try
    {
        int n;
        assert(cin >> n);
        assert(n >= 1 && n <= 100000);
        for (int i = 1; i <= n; i++)
        {
            assert(cin >> p[i]);
            assert(p[i] <= n);
            if (p[i] != -1)
                graph[p[i]].push_back(i);
        }
        int k;
        assert(cin >> k);
        for (int i = 1; i <= k; i++)
        {
            int val;
            assert(cin >> val);
            assert(val <= n && val >= 1);
            to_delete[val] = 1;
        }
        dfs(1);
        cout << ans;
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
