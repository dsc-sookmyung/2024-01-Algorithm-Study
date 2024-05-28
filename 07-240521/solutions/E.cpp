#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dp[1001], maxVal[1001][1001], minVal[1001][1001];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    int ans = 0;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) {
        maxVal[i][i] = minVal[i][i] = arr[i];
        for (int j = i + 1; j < N; j++) {
            maxVal[i][j] = max (maxVal[i][j - 1], arr[j]);
            minVal[i][j] = min (minVal[i][j - 1], arr[j]);
        }
        dp[i] = maxVal[0][i] - minVal[0][i];
        for (int j = 0; j < i; j++)
            dp[i] = max (dp[j] + maxVal[j + 1][i] - minVal[j + 1][i], dp[i]);
        ans = max (ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}
