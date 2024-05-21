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
bool visited[5005];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    visited[0] = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) continue;
        for (int j = i + 1; j < N; j++) {
            int cost = (j - i) * (1 + abs (arr[i] - arr[j]));
            if (cost <= K) visited[j] = true;
        }
    }
    if (visited[N - 1]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
