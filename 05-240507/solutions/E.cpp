#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool visited[MAX];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int s;
    cin >> s;
    int ans = 1;
    queue<int> q;
    visited[s - 1] = true;
    q.push (s - 1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int nx = cur - arr[cur];
        if (nx >= 0 && nx < N && !visited[nx]) {
            visited[nx] = true;
            q.push (nx);
            ans++;
        }
        nx = cur + arr[cur];
        if (nx >= 0 && nx < N && !visited[nx]) {
            visited[nx] = true;
            q.push (nx);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
