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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		cases
		{
			int n, k, i;
			cin >> n >> k;
			vi arr(n, false);
			char c[n], lastVowel;
			loop(i, n - 1)
			{
				cin >> c[i];
				if (c[i] < 97)
				{
					c[i] = (char)(c[i] + 32);
				}
				//use xor here
				if ((c[i] ^ lastVowel) && (c[i] - 32 ^ lastVowel))
				{
					if ((c[i] ^ 'a') || c[])
				}
			}

			//logic is maintain an array with true in pos where new vowel is marked as true

			//then loop over that array and make a counter if counter is greater than max than update max
		}
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
