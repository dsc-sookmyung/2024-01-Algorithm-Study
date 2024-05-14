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
int N, M;
int dp[10001][505];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    vector<int> d(N, 0);
    for (int i = 0; i < N; i++) cin >> d[i];
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= M && i - j > 0; j++)
            dp[i][0] = max (dp[i][0], dp[i - j][j]);
        for (int j = 1; j <= M && j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1] + d[i - 1];
    }
    cout << dp[N][0] << "\n";
    return 0;
}
