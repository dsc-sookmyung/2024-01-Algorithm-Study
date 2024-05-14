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
vector<int> swch[2002];
int cnt[2002];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        swch[i].resize (t);
        while (t--) cin >> swch[i][t], cnt[swch[i][t]]++;
    }
    bool ans = false;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (auto& it : swch[i]) {
            if (cnt[it] == 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = true;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
