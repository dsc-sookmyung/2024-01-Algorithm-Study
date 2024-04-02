#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;

int N;
vector<int> arr;
int oper[4];
vector<int> seq;
int min_ans = INF, max_ans = -INF;

void backtrack (int step)
{
    if (step == N)
    {
        int ans = arr[0];
        for (int i = 1; i < N; i++)
        {
            if (seq[i - 1] == 0)
                ans += arr[i];
            else if (seq[i - 1] == 1)
                ans -= arr[i];
            else if (seq[i - 1] == 2)
                ans *= arr[i];
            else
                ans /= arr[i];
        }
        min_ans = min (min_ans, ans);
        max_ans = max (max_ans, ans);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (!oper[i]) continue;

            oper[i]--;
            seq.push_back (i);
            backtrack (step + 1);
            seq.pop_back ();
            oper[i]++;
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N;
    arr.resize (N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < 4; i++)
        cin >> oper[i];
    backtrack (1);
    cout << max_ans << "\n" << min_ans << "\n";
    return 0;
}
