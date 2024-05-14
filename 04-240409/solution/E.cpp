#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> prefix_sum(N, 0);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = N - 2; i >= 0; i--)
    {
        prefix_sum[i] = prefix_sum[i + 1];
        if (arr[i] > arr[i + 1])
            prefix_sum[i]++;
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int x, y;
        cin >> x >> y;
        cout << prefix_sum[x - 1] - prefix_sum[y - 1] << "\n";
    }
    return 0;
}
