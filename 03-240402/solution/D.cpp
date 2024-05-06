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

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        string str1, str2;
        cin >> N;
        cin >> str1;
        cin >> str2;
        int w = 0, b = 0;
        for (int i = 0; i < N; i++)
        {
            if (str1[i] != str2[i]) {
                if (str1[i] == 'W') w++;
                else b++;
            }
        }
        int minVal = min (w, b);
        int ans = w + b - minVal;
        cout << ans << "\n";

    }
    return 0;
}
