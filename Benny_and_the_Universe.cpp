/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/benny-and-the-universe/
 */

#include <bits/stdc++.h>

//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define uns unsigned
#define usi uns short int //
#define ui uns int
#define ull uns long long
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
#define mp make_pair;
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
        //write your code here
        int n, q, i;
        cin >> n >> q;
        vull d(n, -1);
        const int maxval = 10000000;
        vi dp(maxval, -1), vis(maxval, 0);
        bool onePres = false, twoPres = false;
        loop(i, n - 1)
        {
            ll val;
            cin >> val;
            if (val < maxval)
            {
                if (!vis[val])
                {
                    d[i] = val;
                    vis[val] = true;
                }
            }
            if (d[i] < maxval)
            {
                vis[d[i]] = 1;
            }
            if (d[i] == 1)
            {
                onePres = true;
            }
            else if (d[i] == 2)
            {
                twoPres = true;
            }
        }

        loop(i, q - 1)
        {

            ll x;
            int j;
            cin >> x;
            if (onePres)
            {
                cout << "YES" << endl;
            }
            else if (twoPres && x % 2 == 0)
            {
                cout << "YES" << endl;
            }
            else if (x < maxval && dp[x] != -1)
            {
                if (dp[x] == 1)
                {
                    cout << "YES" << endl;
                }
                else if (dp[x] == 0)
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                bool flag = false;
                loop(j, n - 1)
                {
                    if (d[j] != -1)
                    {
                        ll rem = x % d[j];
                        if (rem < maxval)
                        {

                            if (rem == 0 || vis[rem])
                            {
                                cout << "YES" << endl;
                                flag = true;
                                break;
                            }
                        }
                    }
                }
                if (!flag)
                    cout << "NO" << endl;
            }
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
