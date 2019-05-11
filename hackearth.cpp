/*
 * author: bmayank
 * URL : PROBLEM_URL
 */

#include <bits/stdc++.h>
#include <regex>
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
    ull t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

const char lineEnd = '\n';

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        //write your code here
        // cases
        // {

        // }
        string str, mainStr = "";
        getline(cin, str);
        // cin >> str;
        smatch m;
        regex b("\\$[\\s0-9\\s]*");
        regex_search(str, m, b);

        for (auto x : m)
        {
            mainStr += x;
        }
        mainStr = mainStr.substr(1);
        regex r("[\\s]*");
        string res;
        regex_replace(back_inserter(res), mainStr.begin(), mainStr.end(), r, "");
        stringstream num(mainStr);
        ll x = 0;
        num >> x;
        cout << x;
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << lineEnd;
    }

    return 0;
}
