#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1007;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int f_dist[MAX][MAX], p_dist[MAX][MAX];

void solve() {
    int N, M;
    cin >> M >> N;
    memset (f_dist, -1, sizeof (f_dist));
    memset (p_dist, -1, sizeof (p_dist));
    vector<string> board(N);
    queue<pi> fq, pq;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '*') {
                f_dist[i][j] = 0;
                fq.push ({i, j});
            }
            if (board[i][j] == '@') {
                p_dist[i][j] = 0;
                pq.push ({i, j});
                board[i][j] = '.';
            }
        }
    }
    while (!fq.empty()) {
        pi cur = fq.front();
        fq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (f_dist[nx][ny] != -1) continue;
            if (board[nx][ny] != '.') continue;
            
            f_dist[nx][ny] = f_dist[cur.X][cur.Y] + 1;
            fq.push ({nx, ny});
        }
    }
    int ans = -1;
    while (!pq.empty()) {
        pi cur = pq.front();
        pq.pop();
        if (cur.X == 0 || cur.X == N - 1 || cur.Y == 0 || cur.Y == M - 1) {
            ans = p_dist[cur.X][cur.Y] + 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (p_dist[nx][ny] != -1) continue;
            if (board[nx][ny] != '.') continue;
            if (f_dist[nx][ny] != -1 && \
                    f_dist[nx][ny] <= p_dist[cur.X][cur.Y] + 1) continue;
            p_dist[nx][ny] = p_dist[cur.X][cur.Y] + 1;
            pq.push ({nx, ny});
        }
    }
    if (ans == -1) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
