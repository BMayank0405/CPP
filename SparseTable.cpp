/*
 * author: bmayank
 * URL : #{problem_url}
 */

#include <bits/stdc++.h>

//optimization of program		loop(i, len - 1)

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

const char lineEnd = '\n';

using namespace std;
void BuildSparseTable(vec<ll> &arr, vec<vll> &table, ull len)
{
	ull i, j;
	loop(i, len - 1)
	{
		table[i][0] = arr[i];
	}
	for (j = 1; (1 << j) <= len; j++)
	{
		for (i = 0; (i + (1 << j) - 1) < len; i++)
		{
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(vec<vll> &table, int start, int end)
{
	int range = (int)log2(end - start + 1);
	return min(table[start][range], table[end - (1 << range) + 1][range]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		//write your code here
		ull len, i;
		cin >> len;
		vll arr(len);
		vec<vll> table(len, vll((int)log2(len) + 1));
		loop(i, len - 1)
		{
			cin >> arr[i];
		}
		BuildSparseTable(arr, table, len);
		cout << query(table, 0, 4) << lineEnd;
		cout << query(table, 4, 7) << lineEnd;
		cout << query(table, 7, 8) << lineEnd;
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << lineEnd;
	}

	return 0;
}
