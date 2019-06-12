#include <bits/stdc++.h>

using namespace std;

vector<int> MaskedArr(1e5 + 1, -1);

int maskVal(int number)
{
	if (MaskedArr[number] == -1)
	{
		int maskedVal = 0;
		for (int i = 1; number / i; i *= 10)
		{
			int digit = number / i % 10;
			maskedVal |= 1 << digit;
		}
		MaskedArr[number] = maskedVal;
	}
	return MaskedArr[number];
}

int sumuptoCurrent(int sum, const vector<int> &IntArr)
{
	if (set == 0)
	{
		return memo[set] = 0;
	}
	if (memo[set] != -1)
		return memo[set];

	int result = 0;
	for (auto num : IntArr)
	{
		int existingVal = maskVal(num);
		if ((sum | existingVal) == sum)
			result = max(sumuptoCurrent(sum ^ maskVal(num), IntArr) + num, result);
	}
	return result;
}

int main()
{
	const int decimal = 1 << 10;
	int N;
	cin >> N;
	vector<int> IntArr(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> IntArr[i];
	}

	int Maxsum = 0;
	for (int i = 0; i < decimal; i++)
	{
		Maxsum = max(Maxsum, sumuptoCurrent(i, IntArr));
	}
	cout << Maxsum << "\n";

	return 0;
}