/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/the-electric-type/
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		int n, i, j;
		// 		int n = 5, i, j;
		ll count = 0;
		cin >> n;
		ll arr[n];
		// 		ll arr[n] = {1, 2, 2, 1, 3};
		// ll arr[n] = {1, 2, 6, 2, 6, 3, 1, 2};
		vi mp(n);
		map<ll, int> p;
		map<ll, int> z;
		loop(i, n - 1)
		{
			cin >> arr[i];
			// mp[arr[i]]++;
		}
		mp[n - 1] = 0;
		// z[arr[n-1]] = 1;

		for (int i = n - 2; i >= 0; i--)
		{
			mp[i] = mp[i + 1] + z[arr[i + 1]];
			z[arr[i + 1]] = 1;
		}

		loop(i, n - 1)
		{

			if (!p[arr[i]])
			{
				p[arr[i]] = 1;

				count += (n - i - 1);
				count -= mp[i];
				// forEach(mp)
				// {
				// 	if (value.second > 1)
				// 	{
				// 		count -= value.second - 1;
				// 	}
				// }
				// map<ll, int> p;
				// loopab(j, i + 1, n - 1, 1)
				// {
				// 	if (!p[arr[j]])
				// 	{
				// 		count++;
				// 		p[arr[j]] = 1;
				// 	}
				// }
			}
			// mp[arr[i]]--;
		}
		cout << count << endl;
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
