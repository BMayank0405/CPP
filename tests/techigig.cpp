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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		cases
		{
			int m, n, phase_Nonzero = 0, state_Nonzero = 0, state_max = -1, phase_max = -1;
			ull phase_sum = 0, state_sum = 0;
			cin >> m >> n;
			for (int i = 0; i < m; i++)
			{
				int p;
				cin >> p;
				if (p > 0)
					phase_Nonzero++;
				if (phase_max < p)
					phase_max = p;
				phase_sum += p;
			}

			for (int i = 0; i < n; i++)
			{
				int s;
				cin >> s;
				if (s > 0)
					state_Nonzero++;
				if (state_max < s)
					state_max = s;
				state_sum += s;
			}

			if (state_sum == phase_sum)
			{
				if ((phase_max > state_Nonzero) || (state_max > phase_Nonzero))
				{
					cout << "NO" << endl;
				}
				else
				{
					cout << "YES" << endl;
				}
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
