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

int cnt[101];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, M;
    cin >> N >> M;
    vector<pi> picts;
    for (int i = 0; i < M; i++) {
        int stud;
        cin >> stud;
        if (cnt[stud]) cnt[stud]++;
        else if (picts.size() != N)
            picts.push_back ({stud, i});
        else {
            cnt[picts[0].X] = 0;
            picts[0] = {stud, i};
        }
        cnt[stud]++;
        sort (picts.begin(), picts.end(), [&](const pi& a, const pi& b) {
                    if (cnt[a.X] != cnt[b.X]) return cnt[a.X] < cnt[b.X];
                    return a.Y < b.Y;
                });
    }
    sort (picts.begin(), picts.end());
    for (auto& it : picts) cout << it.X << " ";
    cout << "\n";
    return 0;
}
