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
#define Pui pair<ui, ui>
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
#define all(c) (c).begin(), (c).end()
#define display(c) \
	forEach(c) { cout << value; }

#define Odd(n) if (n & 1)
#define cases \
	ull t;      \
	cin >> t;   \
	while (t--)
//end of helper code

//debugging code
#define deb(x) cout << (#x) << " is " << (x) << endl

using namespace std;

vector<vector<int>> arr;

void Comb(int min, int rem, vi arrCp)
{
	arrCp.eb(min);
	if (rem == 0)
	{
		arr.eb(arrCp);
	}
	else
	{

		int i;
		loopab(i, min, rem, 1)
		{
			if (rem - i >= 0)
			{

				Comb(i, rem - i, arrCp);
			}
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
		//write your code here
		int n, i;
		cin >> n;
		// n = 5;
		vi arrCp;
		loopab(i, 1, n, 1)
		{
			Comb(i, n - i, arrCp);
		}
		forEach(arr)
		{
			display(value);
			cout << endl;
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
