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
int arr[1001][1001], dp[1001][1001];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }
    dp[0][0] = arr[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > 0) dp[i][j] = max (dp[i][j], dp[i - 1][j] + arr[i][j]);
            if (j > 0) dp[i][j] = max (dp[i][j], dp[i][j - 1] + arr[i][j]);
            if (i > 0 && j > 0 ) dp[i][j] = max (dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
        }
    }
    cout << dp[N - 1][M - 1] << "\n";
    return 0;
}
