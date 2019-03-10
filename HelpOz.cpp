/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/a-simple-task/
 */

#include <bits/stdc++.h>
// #include <algorithm>
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
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant < (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)

#define Odd(n) if (n & 1)
#define cases \
    int t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

using namespace std;

void printFactors(ll num)
{
    ll m = num;
    set<ll> factorSet;
    factorSet.insert(num);
    for (int i = 2; i < m; i++)
    {
        if (num % i == 0)
        {
            factorSet.insert(i);
            m = num / i;
            factorSet.insert(m);
        }
    }
    forEach(factorSet)
    {
        cout << value << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        ll prev = 0, current, hcf = 1;
        int j, len;
        cin >> len;
        vector<ll> vect(len);

        //write your code here
        loop(j, len)
        {
            cin >> current;
            vect[j] = current;
        }

        ll diff;
        loopab(j, 1, len, 1)
        {
            diff = abs(vect[j] - vect[j - 1]);
            if (hcf == 1)
                hcf = diff;

            else
                hcf = __gcd(diff, hcf);
        }
        printFactors(hcf);
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    //ending time of program
    return 0;
}
