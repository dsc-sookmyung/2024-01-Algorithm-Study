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
int n, x, y, ans;
bool visited[22];
int seq[33];

void backtrack (int step) {
    if (step > n) {
        ans++;
        return;
    }
    if (visited[step]) {
        backtrack (step + 1);
        return;
    }
    for (int i = 1; i < 2 * n; i++) {
        if (i + step + 1 > 2 * n) break;
        if (seq[i] || seq[i + step + 1]) continue;
        seq[i] = seq[i + step + 1] = step;
        visited[step] = true;
        backtrack (step + 1);
        visited[step] = false;
        seq[i] = seq[i + step + 1] = 0;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> n >> x >> y;
    visited[y - x - 1] = true;
    seq[x] = seq[y] = y - x - 1;
    backtrack (1);
    cout << ans << "\n";
    return 0;
}

