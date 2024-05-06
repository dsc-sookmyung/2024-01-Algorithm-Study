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

    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort (arr.begin(), arr.end());
    int ptr1 = 0, ptr2 = 0;
    int ans = 2e9 + 7;
    for (ptr1 = 0; ptr1 < N; ptr1++) {
        if (ptr2 < ptr1) ptr2 = ptr1;
        while (ptr2 < N - 1 && arr[ptr2] - arr[ptr1] < M)
            ptr2++;
        if (arr[ptr2] - arr[ptr1] < M) continue;
        ans = min (ans, arr[ptr2] - arr[ptr1]);
    }
    cout << ans << "\n";
    return 0;
}
