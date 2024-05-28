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

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, X;
    cin >> N >> X;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0, cnt = 1, cur = 0;
    for (int i = 0; i < X; i++) cur += arr[i];
    ans = cur;
    for (int i = X; i < N; i++) {
        cur = cur - arr[i - X] + arr[i];
        if (cur > ans) ans = cur, cnt = 0;
        if (cur == ans) cnt++;
    }
    if (ans == 0) cout << "SAD\n";
    else cout << ans << "\n" << cnt << "\n";
    return 0;
}
