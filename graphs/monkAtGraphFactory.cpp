/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-at-the-graph-factory/
 */

#include <bits/stdc++.h>

//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define u unsigned
#define usi u short int //
#define ui u int
#define ull u long long
#define power9 (int)(1e9 + 7)
#define totalChars 25
#define Pi pair<int, int>
#define Pui pair<ui, ui>
#define vec vector
#define vi vec<int>
#define vusi vec<usi>
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
	ull t;      \
	cin >> t;   \
	while (t--)
//end of helper code

//debugging code
#define deb(x) cout << (#x) << " is " << (x) << endl

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		usi n, i, totalNodes = 0, j;
		cin >> n;
		vusi arr(n, 0);
		loop(i, n - 1)
		{
			cin >> arr[i];
		}
		loop(i, n - 1)
		{
			totalNodes += arr[i];
			loopab(j, i + 1, n - 1, 1)
			{
				if (arr[j] > 0)
				{
					arr[j]--;
					arr[i]--;
				}
				if (arr[i] == 0)
					break;
			}
		}
		if (totalNodes <= n - 1)
		{
			cout << "Yes";
		}
		else
			cout << "No";
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
