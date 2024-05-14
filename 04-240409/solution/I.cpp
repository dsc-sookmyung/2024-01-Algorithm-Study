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
int arr[1001][1001], dist[1001][1001][2];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    memset (dist, -1, sizeof (dist));
    int N, M;
    cin >> N >> M;
    pi h, e;
    cin >> h.X >> h.Y;
    cin >> e.X >> e.Y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> arr[i][j];
    }
    queue<pii> q;
    q.push ({h, 0});
    dist[h.X][h.Y][0] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.X.X == e.X && cur.X.Y == e.Y) {
            cout << dist[cur.X.X][cur.X.Y][cur.Y] << "\n";
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.X.X + dx[i];
            int ny = cur.X.Y + dy[i];
            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            int nc = cur.Y + arr[nx - 1][ny - 1];
            if (nc >= 2) continue;
            if (dist[nx][ny][nc] != -1) continue;
            dist[nx][ny][nc] = dist[cur.X.X][cur.X.Y][cur.Y] + 1;
            q.push ({{nx, ny}, nc});
        }
    }
    cout << "-1\n";
    return 0;
}
