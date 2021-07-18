/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/min-cost-2-fe2d3308/
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
        cases{
          int n, zeroCount = 0, oneCount = 0, i, val , evenOne=0 , evenZero=0 , placesToSwap =0, costZeroToOne , oneSwap=0, zeroSwap = 0, costOneToZero , val;
          cin >> n >> costZeroToOne >> costOneToZero;
					vi arr(n,0);
					loop(i, n -1){
						cin >> arr[i];
						if(i==0 ){
							val = arr[i];
						}
						else {
							val ^= arr[i];
						}

						if(arr[i]){
							oneCount++;
						}
						else {
							zeroCount++;
						}
					}

					// int valTofind = 0;
					// if(oneCount %2 != 0) valTofind = 1;
					if(val != 0){

					loop(i, n-1){
						if(i%2 == 0 && arr[i] == 1){
							evenOne++;
						}
						else if(i%2 == 0 && arr[i] ==0){
							evenZero++;
						}
					}

					if(oneCount - evenOne >= evenOne ){
						//swap  all odd 1's places
						oneSwap = (oneCount - evenOne);
					}
					else {
						// swap all even 1's places
						oneSwap = evenOne;
					}

					placesToSwap = costOneToZero * oneSwap;


					if(zeroCount - evenZero >= evenZero ){
						//swap  all odd 1's places
						zeroSwap = (zeroCount - evenZero);
					}
					else {
						// swap all odd 1's places
						zeroSwap = evenZero;
					}

					placesToSwap += (costZeroToOne * zeroSwap);


					cout << placesToSwap << endl;
					}
					cout << 0 << endl;
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
