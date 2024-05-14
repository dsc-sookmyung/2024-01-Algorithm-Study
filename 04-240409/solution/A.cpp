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

    int A, B, C, N;
    cin >> A >> B >> C >> N;
    bool ans = false;
    for (int i = 0; i * C <= N && !ans; i++) {
        for (int j = 0; i * C + j * B <= N && !ans; j++) {
            int remain = N - i * C - j * B;
            if (remain % A == 0) ans = true;
        }
    }
    cout << ans << "\n";
    return 0;
}
