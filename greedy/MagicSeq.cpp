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
		ui n, i, len;
		cin >> n;
		len = 2 * n;
		stack<pair<char, int>> s;
		ull count = 0;
		loop(i, len - 1)
		{
			char c;
			cin >> c;
			if (c == ')')
			{
				if (!s.empty())
				{
					if (s.top().first == '(')
					{
						s.pop();
					}
					else if (s.top().first == ')')
					{
						s.push({c, i});
					}
				}
				else
				{
					s.push({c, i});
				}
			}
			else if (c == '(')
			{
				s.push({c, i});
			}
		}
		vi closing, opening;
		while (!s.empty())
		{
			while (s.top().first == '(')
			{
				opening.eb(s.top().second);
				s.pop();
			}
			while (!s.empty() && s.top().first == ')')
			{
				closing.eb(s.top().second);
				s.pop();
			}
		}
		int j = opening.size() - 1, k = 0;
		while (j >= 0 && k < closing.size())
		{
			count += ((opening[j] - closing[i]) + 1) / 2;
			j--;
			i++;
		}

		cout << count;
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
