#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define vec vector
#define vi vec<int>

using namespace std;

ull noEdges = 0;
int k;

void AddEdge(vec<vi> &tree, int u, int v)
{
    tree[u].emplace_back(v);
}

ll DfsSum(vec<vi> &tree, int arr[], int index)
{
    int currNodeVal = arr[index];
    vec<ll> sum(tree[index].size());

    for (int j = 0; j < tree[index].size(); ++j)
    {
        sum[j] = DfsSum(tree, arr, tree[index][j]);
    }
    if (currNodeVal > k)
    {
        if (sum.empty())
        {
            noEdges++;
        }
        else
        {
            noEdges += 2;
        }

        return 0;
    }

    ll totalChildSum = 0;
    for (int g = 0; g < sum.size(); g++)
    {
        if (currNodeVal + sum[g] > k)
        {
            noEdges++;
        }
        else
        {
            totalChildSum += sum[g];
        }
    }

    ll totalSum = totalChildSum + currNodeVal;
    while (totalSum > k)
    {
        noEdges++;
        int index = distance(sum.begin(), max_element(sum.begin(), sum.end()));
        totalSum -= sum[index];
        sum[index] = 0;
    }
    return totalSum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, u, v;
    cin >> N >> k;

    vec<vi> tree(N, vi());
    int arr[N + 1] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        AddEdge(tree, u, v);
    }
    DfsSum(tree, arr, 0);
    cout << noEdges;

    return 0;
}

/*

7 8
4 3 2 7 2 1 6
1 2
1 3
1 4
3 5
3 6
4 7



 */