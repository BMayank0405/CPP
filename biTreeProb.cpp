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
#define power9 1000000007
#define power5 100007
#define totalChars 25
#define P pair<int, int>
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

void updateBITree(vector<ll> &BITreeArr, ui startIndex, ll val)
{
	ull size = BITreeArr.size();
	for (; startIndex < size; startIndex += startIndex & (-startIndex))
	{
		BITreeArr[startIndex] *= val;
	}
}

ll query(vector<ll> &BITreeArr, ui endIndex)
{
	ll sum = 0;
	for (; endIndex > 0; endIndex -= endIndex & (-endIndex))
	{
		sum += BITreeArr[endIndex];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		ull n, i, val;
		cin >> n;
		vector<ll> BITree(n + 1, 0);
		vector<ll> Arr(n);

		//construct BITree
		loopab(i, 1, n, 1)
		{
			cin >> val;
			Arr[i] = val;
			updateBITree(BITree, i, val);
		}
		}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
