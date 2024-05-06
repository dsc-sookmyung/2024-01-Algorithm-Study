#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

    ull n;
    cin >> n;

    ull left = 0, right = 1ULL << 32;
    ll mid = (left + right) / 2;
    while (left < right) {
        if (mid * mid >= n) right = mid;
        else left = mid + 1;
        mid = (left + right) / 2;
    }
    cout << mid << "\n";
    return 0;
}
