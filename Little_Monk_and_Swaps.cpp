/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/little-monk-and-swaps/
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
    ull t;    \
    cin >> t; \
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
        int N, i;
        cin >> N;
        int arr[N] = {0};
        loopab(i, 1, N - 2, 1)
        {
            cin >> arr[i];
        }
        ull count = 0;
        loopab(i, 1, N - 2, 1)
        {
            if ((arr[2 * i] > arr[2 * i + 1]) && (arr[2 * i] > 0 && arr[2 * i + 1] > 0))
            {
                swap(arr[2 * i], arr[2 * i + 1]);
                count++;
            }
            if (arr[2 * i] > arr[i] && (arr[2 * i] > 0 && arr[i] > 0))
            {
                swap(arr[2 * i], arr[i]);
                count++;
            }
            if (arr[2 * i + 1] < arr[i] && (arr[2 * i + 1] > 0 && arr[i] > 0))
            {
                swap(arr[i], arr[2 * i + 1]);
                count++;
            }
        }
        cout << count << endl;
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
