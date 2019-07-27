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
#define deb(x) cout << (#x) << " is " << (x) << "\n"

using namespace std;

long long power(long long base, long long exponent, long long modulus)
{
	long long result = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		ull t, q = 0;
		cin >> t;
		while (q < t)
		{
			int n, i;
			ll ans = 1;
			cin >> n;
			vi arr(n, 0);
			loop(i, n - 1)
			{
				cin >> arr[i];
			}
			i = 0;
			while (i < n)
			{
				vi arr2;
				ll maxNum = 1, maxDen = 0;
				int j;
				while (arr[i] > 1)
				{
					arr2.eb(arr[i]);
					i++;
				}
				loop(j, arr2.size() - 1)
				{
					maxNum = (maxNum * arr2[j]) % power9;
					maxDen = (maxDen + arr2[j]) % power9;
				}
				ll max2 = power(maxDen, power9 - 2, power9);
				// deb(max2);
				max2 = (max2 * maxNum) % power9;
				ans = max(ans, max2);
				while (arr[i] <= 1)
				{
					i++;
				}
			}

			cout << "Case #" << q + 1 << ": " << ans << endl;
			q++;
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
