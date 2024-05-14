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
//const int MOD = 998'244'353;
const int INF = 1e9 + 7;
int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int degree[100'001];

int main (void) {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t, k;
        cin >> t >> k;
        if (t == 2) cout << "yes\n";
        else {
            if (degree[k] == 1) cout << "no\n";
            else cout << "yes\n";
        }
    }
    return 0;
}
