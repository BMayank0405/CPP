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
		const string startP = "Motu", endP = "Patlu", tie = "Tie";
		cases
		{
			int n, i, m;

			cin >> n;

			if (n == 1)
			{
				int temp;
				cin >> temp;
				cout << 1 << " " << 0 << endl;
				cout << startP << endl;
			}
			else
			{
				m = (n / 2);
				double arr[n];
				double start = 0, end = 0;
				loop(i, n - 1)
				{
					cin >> arr[i];
				}

				int totalCount = n - 2, countS = 1, countE = 1, PosS = 0, PosE = n - 1;

				start = arr[0] / 2;
				end = arr[n - 1];
				PosS++;
				PosE--;
				while (totalCount > 0)
				{

					while ((start < end) && totalCount > 0)
					{
						start += (arr[PosS] / 2);
						PosS++;
						totalCount--;
						countS++;
					}
					while ((end < start) && totalCount > 0)
					{
						end += arr[PosE];
						PosE--;
						totalCount--;
						countE++;
					}
					while ((end == start) && totalCount > 0)
					{
						start += (arr[PosS] / 2);
						PosS++;
						countS++;
						totalCount--;
						if (totalCount > 0)
						{
							end += arr[PosE];
							PosE--;
							totalCount--;
							countE++;
						}
					}
				}
				cout << countS << " " << countE << endl;
				if (countS > countE)
				{
					cout << startP << endl;
				}
				else if (countS < countE)
				{
					cout << endP << endl;
				}
				else if (countS == countE)
				{
					cout << tie << endl;
				}
			}
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}

/*


11
5
2 6 2 1 7
5
2 9 8 2 7
1
15
4
15 1 1 1
2
2 1
2
15654 1516
15
15531 151 1412 142 1864 154 14 121 15 17 18 19 16 14 15
1
651514
3
145 154 1323
5
11 111 223 26 1
4
14575 1 12 14

 */