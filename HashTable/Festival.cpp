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
#define vui vec<ui>
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
#define deb(x) cout << (#x) << " is " << (x) << endl

using namespace std;

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
			map<string, priority_queue<ui, vector<ui>, greater<ui>>> mp;
			loop(i, n - 1)
			{
				ui x;
				string s;
				cin >> s >> x;
				auto val = mp[s];
				if (mp[s].size() == 3)
				{
					if (x > mp[s].top())
					{
						mp[s].pop();
						mp[s].push(x);
					}
				}
				else
				{
					mp[s].push(x);
				}
			}
			pair<string, ll> res;
			res.second = 0;
			forEach(mp)
			{
				auto val = value.second;
				ull sum = 0;
				while (val.size() > 0)
				{
					sum += val.top();
					val.pop();
				}
				if (sum > res.second)
					res = {value.first, sum};
			}
			cout << res.first << " " << res.second << endl;
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
