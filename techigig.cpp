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
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)

#define Odd(n) if (n & 1)
#define cases \
	short t;    \
	cin >> t;   \
	while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

const char lineEnd = '\n';

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
			ui size, i;
			cin >> size;
			vector<ll> elements(size);
			vector<ll> sum(size);
			vector<ll> arrOfEl(size);
			loop(i, size - 1)
			{
				cin >> elements[i];
			}

			for (ui x = size - 1; x >= 0; x--)
			{
				//check for right sub array
				//check for sum
				ll rightSum = 0;
				vector<ll> rightSubArr;
				if (elements[x] > 0)
				{

					if (x + 1 < size)
					{
						ull max = 0, index = -1;

						//finding max
						for (ui j = x + 2; j < size; j++)
						{
							if (sum[j] > max)
							{
								max = sum[j];
								index = j;
							}
						}
						//now pick the rightsub array from index
						if (index > -1)
						{
							vector<ll> arraytofound;
							arraytofound = arrOfEl[index];
							rightSum = max;
							arraytofound.push_back(elements[x]);
							rightSubArr = arraytofound;
						}
					}
				}
				sum[x] = elements[x] + rightSum;
				//correct here
				// arrOfEl[x] = rightSubArr;
			}
			cout << lineEnd;
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << lineEnd;
	}

	return 0;
}
