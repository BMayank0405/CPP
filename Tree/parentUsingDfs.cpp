/*
 * author: bmayank
 * URL : #{problem_url}
 */

#include <bits/stdc++.h>

//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define power9 (int)(1e9 + 7)
#define totalChars 25
#define Pi pair<int, int>
#define vec vector
#define vi vec<int>
#define vll vec<ll>
#define vull vec<ull>
#define endl "\n";
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)

#define Odd(n) if (n & 1)
#define cases \
	ull t;      \
	cin >> t;   \
	while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

using namespace std;

//function for making adjancy list for a particular tree
void AddEdge(vec<vi> &tree, int u, int v)
{
	tree[u].eb(v);
}
ull totalcount = 0;

//function for printing dfs from a particular node
void Bfs(vec<vi> &tree, int index)
{
	queue<int> q;
	q.push(index);

	while (!q.empty())
	{
		int ind = q.front();
		q.pop();
		cout << ind << endl;
		int i;
		for (int i = 0; i < tree[ind].size(); ++i)

			q.push(tree[ind][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		//write your code here
		int V, u, v;
		// cin >> V;
		cin >> V;
		vec<vi> tree(V, vi());

		vec<bool> del(V, false);
		cin >> u;
		for (int i = 1; i < V; i++)
		{
			cin >> u;
			if (u != -1)
			{
				u--;
				AddEdge(tree, u, i);
			}
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
