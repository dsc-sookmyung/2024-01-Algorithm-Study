#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> edge;
vector<bool> visited;
int cnt=0;

void dfs(int node){
    visited[node] = true;
    for (auto it : edge[node])
    {
        if (!visited[it])
        {
            cnt++;
            dfs (it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> m;
    cin >> n;
    for(int i = 0; i <= m; i++){
        vector<int> tmp;
        edge.push_back(tmp);
        visited.push_back(false);
    }

    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs (1);
    cout << cnt << "\n";
    return 0;
}
