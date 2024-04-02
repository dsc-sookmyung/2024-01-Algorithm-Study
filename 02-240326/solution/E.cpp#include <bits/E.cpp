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
int cnt[100001];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0;
    int l = 0, r = 0;
    while (r < N && cnt[arr[r]] < K) {
        cnt[arr[r]]++;
        r++;
        ans = max (ans, r - l);
    }
    for (l = 1; l < N; l++) {
        cnt[arr[l - 1]]--;
        while (r < N && cnt[arr[r]] < K) {
            cnt[arr[r]]++;
            r++;
            ans = max (ans, r - l);
        }
    }
    cout << ans << "\n";
    return 0;
}
