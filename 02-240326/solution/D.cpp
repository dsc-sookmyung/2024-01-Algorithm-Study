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

    string str;
    cin >> str;
    string quack = "quack";
    map<char, int> m = { {'q', 0}, {'u', 1}, {'a', 2}, {'c', 3}, {'k', 4}};
    int idx = 0, ans = 0;
    int cnt[6] = {0, };
    for (auto& c : str) {
        idx = m[c];
        if (idx == 0) {
            if (cnt[4] != 0) {
                cnt[4]--;
                cnt[0]++;
            } else {
                ans++;
                cnt[0]++;
            }
        } else {
            if (cnt[idx - 1] == 0) {
                ans = -1;
                break;
            } else {
                cnt[idx - 1]--;
                cnt[idx]++;
            }
        }
    }
    if (cnt[0] || cnt[1] || cnt[2] || cnt[3]) ans = -1;
    cout << ans << "\n";
    return 0;
}
