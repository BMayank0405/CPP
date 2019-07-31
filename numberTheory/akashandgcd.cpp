/*
 * author: bmayank
 * URL : PROBLEM_URL
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
#define mod (int)(1e6 + 3)
#define power9 (int)(1e9 + 7)
#define power5 100007
#define totalChars 25
#define P pair<int, int>
#define vi vector<int>
#define vll vector<vll>
#define vull vector<ull>
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)

#define Odd(n) if (n & 1)
#define cases \
    ll t;     \
    cin >> t; \
    while (t--)
//end of helper code
//
//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

using namespace std;

void func(vector<ull> &gcdsum, ull x)
{
    if (x == 1)
        gcdsum[1] = 1;
    if (gcdsum[x] == 0)
    {
        ull y;
        loopab(y, 2, x, 1)
        {
            gcdsum[x] += y / __gcd(y, x);
        }
        gcdsum[x] += 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {

        //write your code here
        ull n, m, i, queries, xVal, yVal;
        char check;
        cin >> n;
        vull fx(n);
        vull gcdsum(mod, 0);
        loop(i, n - 1)
        {
            cin >> m;
            fx[i] = m;
            func(gcdsum, m);
        }
        cin >> queries;
        while (queries--)
        {
            cin >> check >> xVal >> yVal;
            xVal--;
            ull sum = 0;
            if (check == 'C')
            {

                yVal--;
                loopab(i, xVal, yVal, 1)
                {

                    sum += (gcdsum[fx[i]]) % power9;
                }
                cout << sum << "\n";
            }
            else if (check == 'U')
            {
                fx[xVal] = yVal;
                func(gcdsum, yVal);
            }
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    //ending time of program
    return 0;
}
