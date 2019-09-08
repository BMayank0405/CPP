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
#define deb(x) cout << (#x) << " is " << (x) << endl

using namespace std;

int convertToMin(int hh1, int mm1)
{
	return hh1 * 60 + mm1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		vi start, end;
		cases
		{

			int hh1, mm1, hh2, mm2;
			cin >> hh1 >> mm1 >> hh2 >> mm2;
			hh1 = convertToMin(hh1, mm1);
			hh2 = convertToMin(hh2, mm2);
			start.eb(hh1);
			end.eb(hh2);
		}

		sort(start.begin(), start.end());
		sort(end.begin(), end.end());

		int count = 0, max = 0, i = 0, j = 0;
		while (i < start.size() && j < end.size())
		{
			int startval = -1, endval = -1;
			if (i < start.size())
			{
				startval = start[i];
			}
			if (j < end.size())
			{
				endval = end[j];
			}
			if (startval <= endval)
			{
				count++;
				i++;
			}
			else
			{
				count--;
				j++;
			}
			if (count > max)
			{
				max = count;
			}
		}
		cout << max;
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}

/*

6
1 0 2 0
16 0 21 30
9 30 13 0
21 30 22 30
21 30 22 30
12 0 12 30

 */