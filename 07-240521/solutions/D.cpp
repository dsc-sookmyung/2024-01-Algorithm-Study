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
int cnt[26][2];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    string a, b;
    while (getline(cin, a), getline(cin, b)) {
        memset (cnt, 0, sizeof (cnt));
        for (auto& c : a) cnt[c - 'a'][0]++;
        for (auto& c : b) cnt[c - 'a'][1]++;
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < min (cnt[c - 'a'][0], cnt[c - 'a'][1]); i++)
                cout << c;
        }
        cout << "\n";
    }
    return 0;
}

