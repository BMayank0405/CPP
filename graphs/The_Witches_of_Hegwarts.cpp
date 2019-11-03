/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/the-witches-of-hegwarts-1/
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
	ull t;      \
	cin >> t;   \
	while (t--)
//end of helper code

//debugging code
#define deb(x) cout << (#x) << " is " << (x) << endl

using namespace std;
const int len = 19999999;
vi arr(len, -1);

int returnMin(int x)
{
	ll retval = 0;
	if (x == 1)
		return 0;
	else
	{
		if (x >= len || arr[x] == -1)
		{

			int y1, y2, y3;
			y1 = y2 = y3 = 0;
			bool removeOne = false;
			if (x % 2 == 0)
			{
				y2 += (returnMin(x / 2) + 1);
			}
			else
			{
				removeOne = true;
				y2 = power9;
			}
			if (x % 3 == 0)
			{
				y3 += (returnMin(x / 3) + 1);
			}
			else
			{
				removeOne = true;
				y3 = power9;
			}
			if (removeOne)
			{
				y1 += (returnMin(x - 1) + 1);
			}
			else
			{
				y1 = power9;
			}
			if (x >= len)
			{
				retval = min({y1, y2, y3});
			}
			else
			{

				arr[x] = min({y1, y2, y3});
			}
		}
		if (x >= len)
		{
			return retval;
		}
		else
		{

			return arr[x];
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
		arr[1] = 0;
		arr[2] = 1;
		arr[3] = 1;
		cases
		{
			int n;
			cin >> n;
			cout << returnMin(n) << endl;
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
