/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/monk-and-divisible-numbers-2/description/
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
#define mod (int)(1e6 + 3)
#define power9 (int)(1e9 + 7)
#define power5 100007
#define totalChars 25
#define P pair<int, int>
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)

#define Odd(n) if (n & 1)
#define cases  \
	long long t; \
	cin >> t;    \
	while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

using namespace std;

ll modExp(ll a, ll b)
{
	a = a % power9;
	b = b % power9;
	ll result = 1;
	while (b > 0)
	{
		Odd(b) result = (result * a) % power9;
		b = b >> 1;
		a = (a * a) % power9;
	}
	return result;
}

void factors(map<ll, ll> &temp_map, ll a, ll c)
{
	//finds all the number from 2 to sqrt(a) which divide a
	for (ll i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			while (a % i == 0)
			{
				temp_map[i]++;
				a /= i;
			}
			if (c > 0)
				temp_map[i] *= c;
		}
	}

	//if any of the number is left it is prime number
	if (a > 1)
	{
		temp_map[a]++;
		if (c > 0)
			temp_map[a] *= c;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		// ifstream mayank("../../testCases.txt");
		// mayank.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
		// if (!mayank.is_open())
		// {
		// 	cerr << "Error opening file" << endl;
		// 	exit(1);
		// }

		//write your code here

		cases
		{
			ll a, b, c;
			cin >> a >> b >> c;
			map<ll, ll> map1, map2;
			factors(map1, a, c);
			factors(map2, b, 0);

			for (auto it = map2.begin(); it != map2.end(); it++)
			{
				if (map1[it->first])
				{
					if (it->second > map1[it->first])
						map2[it->first] = it->second - map1[it->first];
					else
						map2[it->first] = 0;
				}
			}

			ll sum = 1;
			for (auto it = map2.begin(); it != map2.end(); it++)
			{
				ll tp = it->second;
				ll val = it->first % mod;
				if (it->second > 0)
				{
					ll ans = modExp(val, it->second);
					sum = (sum * ans) % power9;
				}
			}
			cout << sum << endl;
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	//ending time of program
	return 0;
}
