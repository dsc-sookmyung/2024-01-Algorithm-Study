#include <bits/stdc++.h>

using namespace std;

int dp[100001], w[101], v[101];
int N, K;

/*
int solve (int i, int j) {
    if (i == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = solve (i - 1, j);
    if (j - w[i] >= 0)
        dp[i][j] = max (dp[i][j], solve (i - 1, j - w[i]) + v[i]);
    return dp[i][j];
}
*/
int main (void)
{
    //memset (dp, -1, sizeof(dp));
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> w[i] >> v[i];
        /*
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0)
                dp[i][j] = max (dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }*/
    for (int i = 1; i <= N; i++) {
        for (int j = K; j - w[i] >= 0; j--) {
            dp[j] = max (dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[K] << "\n";
    return 0;
}
