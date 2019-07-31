/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/e-16/
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

bool compareLen(const std::string &a, const std::string &b)
{
	return (a.size() < b.size());
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{

		int n;
		cin >> n;
		int arr[n], maxEl = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			if (maxEl < arr[i])
				maxEl = arr[i];
		}

		vi mp(maxEl, 0);
		for (int i = 0; i < n; ++i)
		{
			mp[arr[i] - 1]++;
		}

		ll max = 0, total = 0;

		for (int i = mp.size() - 1; i >= 0; --i)
		{
			if (max > mp[i])
			{
				total += max - mp[i];
			}
			else
			{
				max = mp[i];
			}
		}

		if (total > 0)
		{
			cout << total << endl;
		}
		else
		{
			//print strings here in ascending order
			int count = mp[0];
			vec<string> p(count, "");
			for (int i = 0; i < mp.size(); ++i)
			{
				for (int j = 0; j < mp[i]; ++j)
				{
					p[j] += to_string(i + 1) + " ";
				}
			}
			sort(p.begin(), p.end());
			cout << p.size() << endl;
			for (int i = 0; i < count; ++i)
			{
				cout << p[i] << endl;
			}
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
