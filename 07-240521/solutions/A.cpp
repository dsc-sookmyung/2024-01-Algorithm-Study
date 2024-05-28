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
int N, M;
vector<int> arr, ans;
bool check[10];

void backtrack (int step, int prev) {
    if (step == M) {
        for (auto& it : ans) cout << it << " ";
        cout << "\n";
        return;
    }
    for (int i = prev + 1; i < N; i++) {
        if (!check[i]) {
            ans.push_back (arr[i]);
            check[i] = true;
            backtrack (step + 1, i);
            check[i] = false;
            ans.pop_back();
        }
    }

}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N >> M;
    arr.resize (N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort (arr.begin(), arr.end());
    backtrack (0, -1);
    return 0;
}
