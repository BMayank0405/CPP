/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/big-travel-icpc-9/
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
#define all(c) (c).begin(), (c).end()
#define display(c) \
    forEach(c) { cout << c << endl; }

#define Odd(n) if (n & 1)
#define cases \
    ull t;    \
    cin >> t; \
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
        ll n, i, c, cx = 0, cy = 0;
        cin >> n;
        c = 2 * n - 1;
        vi arrX(n), arrY(n);
        loop(i, n - 1)
        {
            cin >> arrX[i] >> arrY[i];
        }
        sort(all(arrX));
        sort(all(arrY));
        loop(i, n - 1)
        {
            ll t = (n - c) % power9;

            cx = (cx + (t * (arrX[i]) % power9) % power9) % power9;
            cy = (cy + (t * (arrY[i]) % power9) % power9) % power9;
            c -= 2;
        }
        cout << (cx + cy) % power9 << endl;
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
