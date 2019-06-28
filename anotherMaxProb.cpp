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

int binarySearch(vi &vect, int val)
{
	int start = 0;
	int end = vect.size();
	if (vect[start] == val)
	{
		return start;
	}
	else if (vect[end] == val)
	{
		return end;
	}
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (vect[mid] == val)
		{
			return mid;
		}
		else
		{
			if (vect[mid] > val)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
	}
	return -1;
}

int findMinimumElement(vi &heap, int n)
{
	int minimumElement = heap[0];

	for (int i = 1; i < n; ++i)
		minimumElement = min(minimumElement, heap[i]);

	return minimumElement;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	try
	{
		int N, i, q;
		cin >> N;
		vi vect;
		loop(i, N - 1)
		{
			int type;
			cin >> type;
			if (type == 1)
			{
				int num;

				cin >> num;
				vect.push_back(num);
				push_heap(vect.begin(), vect.end());
			}
			else if (type == 2)
			{
				//remove element
				int val;
				cin >> val;
				int ind = binarySearch(vect, val);
				if (ind != -1)
				{
					swap(vect[ind], vect.back());
					vect.pop_back();
					push_heap(vect.begin(), vect.end());
					// while(i)
				}
				else
				{
					cout << -1 << endl;
				}
			}
			else if (type == 3)
			{
				//find max
				cout << vect.front() << endl
			}
			else if (type == 4)
			{
				cout << findMinimumElement(vect, vect.size()) << endl;
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

10
1 5
3
3
3
1 4
1 1
1 8
3
1 6
4

 */