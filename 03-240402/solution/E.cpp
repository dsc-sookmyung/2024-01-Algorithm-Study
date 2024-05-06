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
int len[33];
string first = "moo";

char solve (int step, int pos) {
    if (step == 0) return first[pos];
    if (pos < len[step - 1]) return solve (step - 1, pos);
    pos -= len[step - 1];
    if (pos == 0) return 'm';
    if (pos <= step + 2) return 'o';
    pos -= step + 3;
    return solve (step - 1, pos);
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    len[0] = 3;
    for (int i = 1; i < 28; i++) len[i] = len[i - 1] * 2 + i + 3;
    cout << solve (27, N - 1) << "\n";
    return 0;
}
