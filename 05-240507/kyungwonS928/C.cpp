#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	int maxSum = 0;
	for (int j = 1; j <= N; j++)
	{
		maxSum = max(maxSum, dp[N][j]);
	}

	cout << maxSum << '\n';
}
