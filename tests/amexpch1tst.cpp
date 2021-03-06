#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> a)
{
    // Write your code here
    long long ans = 0, temp;
    int n = a.size();
    for (int i = n; i > 0; i--)
    {
        temp = 0;
        for (int j = 1; j <= n; j++)
        {
            for (int k = n; k > 0; k--)
            {
                if (k >= i && i >= j && a[k] < a[i])
                {
                    temp++;
                }
            }
        }

        // temp = (i - 1) * temp;
        ans += (temp / (i));
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i_a = 0; i_a < n; i_a++)
    {
        cin >> a[i_a];
    }

    long long out_;
    out_ = solve(a);
    cout << out_;
}