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
int dist[100001];

bool avail (int n) {
    if (n < 0 || n > 100000) return false;
    if (dist[n] != -1) return false;
    return true;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int A, B, N, M;
    memset (dist, -1, sizeof (dist));
    cin >> A >> B >> N >> M;
    dist[N] = 0;
    queue<int> q;
    q.push (N);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == M) break;
        int nx = cur - 1;
        if (avail (nx)) {
            dist[nx] = dist[cur] + 1;
            q.push (nx);
        }
        nx = cur + 1;
        if (avail (nx)) {
            dist[nx] = dist[cur] + 1;
            q.push (nx);
        }
        nx = cur - A;
        if (avail (nx)) {
            dist[nx] = dist[cur] + 1;
            q.push (nx);
        }
        nx = cur + A;
        if (avail (nx)) {
            dist[nx] = dist[cur] + 1;
            q.push (nx);
        }
        nx = cur - B;
        if (avail (nx)) {
            dist[nx] = dist[cur] + 1;
            q.push (nx);
        }
        nx = cur + B;
        if (avail (nx)) {
            dist[nx] = dist[cur] + 1;
            q.push (nx);
        }
        nx = cur * A;
        if (avail (nx)) {
            dist[nx] = dist[cur] + 1;
            q.push (nx);
        }
        nx = cur * B;
        if (avail (nx)) {
            dist[nx] = dist[cur] + 1;
            q.push (nx);
        }
    }
    cout << dist[M] << "\n";
    return 0;
}
