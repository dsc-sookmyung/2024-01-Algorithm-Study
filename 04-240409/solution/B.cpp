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
string str;
int N, len;
bool visited[55];
vector<int> nums;

bool backtrack (int idx) {
    if (idx == len) {
        for (auto& it : nums) cout << it << " ";
        cout << "\n";
        return true;
    }
    if (str[idx] == '0') return false;
    int num1 = str[idx] - '0';
    if (num1 > 0 && num1 <= N && !visited[num1]) {
        visited[num1] = true;
        nums.push_back (num1);
        if (backtrack (idx + 1)) return true;
        nums.pop_back();
        visited[num1] = false;
    }
    if (idx == len - 1) return false;
    int num2 = str[idx] - '0';
    num2 = num2 * 10 + str[idx + 1] - '0';
    if (num2 > 0 && num2 <= N && !visited[num2]) {
        visited[num2] = true;
        nums.push_back (num2);
        if (backtrack (idx + 2)) return true;
        nums.pop_back();
        visited[num2] = false;
    }
    return false;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> str;
    for (int i = 1; i <= 50; i++) {
        if (i < 10) len++;
        else len += 2;
        if (str.length() == len) {
            N = i;
            break;
        }
    }
    backtrack (0);
    return 0;
}
