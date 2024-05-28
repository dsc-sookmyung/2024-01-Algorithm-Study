#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
vector<string> map;

void floydWarshall ()
{
    vector<vector<int>> dist (N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (map[i][j] == 'Y')
            {
                dist[i][j] = 1;
                dist[j][i] = 1;
            }
        }
    }
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == k) continue;
                if (dist[i][j] && dist[j][k])
                {
                    if (!dist[i][k])
                        dist[i][k] = dist[i][j] + dist[j][k];
                    else
                        dist[i][k] = min (dist[i][k], dist[i][j] + dist[j][k]);
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] == 1 || dist[i][j] == 2)
                cnt++;
        }
        ans = max (cnt, ans);
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N;
    map.resize (N);
    for (int i = 0; i < N; i++)
        cin >> map[i];
    floydWarshall();
    cout << ans << "\n";
    return 0;
}
