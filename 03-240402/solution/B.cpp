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
int dist[101][101];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    ll cost = 1e18 + 7;
    pi ans;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            ll tmp_cost = 0;
            for (int u = 1; u <= N; u++)
                tmp_cost += min (dist[u][i], dist[u][j]) * 2;
            if (tmp_cost < cost) {
                cost = tmp_cost;
                ans = {i, j};
            }
        }
    }
    cout << ans.X << " " << ans.Y << " " << cost << "\n";
    return 0;
}
