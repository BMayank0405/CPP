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
			int boolarr[100001] = {false};
			ll sum = 0;
			int N, i;
			cin >> N;
			vi arr(N);
			loop(i, N - 1)
			{
				cin >> arr[i];
			}
			sort(arr.begin(), arr.end());

			for (int j = N - 1; j >= 0; j--)
			{
				string s = to_string(arr[j]);
				bool flag = true;
				for (int z = 0; z < s.length(); z++)
				{
					if (boolarr[s[z]])
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					for (int z = 0; z < s.length(); z++)
					{
						boolarr[s[z]] = true;
					}

					sum += arr[j];
				}
			}
			cout << sum << endl;
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
