/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/the-random-walker-09a8ea3d/
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
        cases
        {
            char a, b;
            int x1, y1, x2, y2, xd, yd, steps = 0;
            cin >> a >> y1;
            cin >> b >> y2;
            x1 = a - 'a';
            x2 = b - 'a';

            while ((x1 != x2) || (y1 != y2))
            {
                xd = x2 - x1;
                yd = y2 - y1;
                int absx = abs(xd), absy = abs(yd);
                if (xd == 0)
                {
                    steps += absy;
                    y1 += yd;
                }
                else if (yd == 0)
                {
                    steps += absx;
                    x1 += xd;
                }
                else
                {

                    if (absx >= absy)
                    {
                        steps += absy;
                        y1 += yd;
                        if (xd > 0)
                        {
                            x1 += absy;
                        }
                        else
                        {
                            x1 -= absy;
                        }
                    }
                    else
                    {
                        steps += absx;

                        x1 += xd;
                        if (yd > 0)
                        {
                            y1 += absx;
                        }
                        else
                        {
                            y1 -= absx;
                        }
                    }
                }
            }
            cout << steps << endl;
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
