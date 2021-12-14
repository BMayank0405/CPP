/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/sum-as-per-frequency-88b00c1f/
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
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)
#define all(c) (c).begin(), (c).end()
#define display(c) \
    forEach(c) { cout << value << endl; }

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
        ll n, i, el, prev = 0, q, l, r;
        cin >> n;
        unordered_map<ll, ll> count_map;
        vi arr(n, 0);
        loop(i , n-1){
            cin >> el;
            if (count_map.find(el) == count_map.end()){
                count_map[el] = 1;
            }
            else {
                 count_map[el] += 1;
            }
        }

        for (auto itr = count_map.begin(); itr != count_map.end(); itr++)
        {
            arr[itr->second-1] = arr[itr->second-1] + (itr->second * itr->first);
        }

        forEach(arr)
        {
            value = value + prev;
            prev = value;
        }
        
        cases{
            cin >> l >> r;
            l--;
            r--;
            if(l> 0){
                cout << arr[r]-arr[l-1] << endl;
            }
            else {
                cout << arr[r] << endl;
            }
        }
        



    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
