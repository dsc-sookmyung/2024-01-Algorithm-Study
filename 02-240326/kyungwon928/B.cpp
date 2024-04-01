#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int nums[11] = {
	0,
};
int operators[4] = {
	0,
};
int max_val = -1000000001, min_val = 1000000001;
void MinAndMax(int result, int idx)
{
	if (idx == N)
	{
		if (result > max_val)
			max_val = result;
		if (result < min_val)
			min_val = result;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (operators[i] > 0)
		{
			operators[i]--;
			if (i == 0)
			{
				MinAndMax(result + nums[idx], idx + 1);
			}
			else if (i == 1)
			{
				MinAndMax(result - nums[idx], idx + 1);
			}
			else if (i == 2)
			{
				MinAndMax(result * nums[idx], idx + 1);
			}
			else
			{
				MinAndMax(result / nums[idx], idx + 1);
			}
			operators[i]++;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> operators[i];
	}

	MinAndMax(nums[0], 1);

	cout << max_val << " \n"
		 << min_val;
}