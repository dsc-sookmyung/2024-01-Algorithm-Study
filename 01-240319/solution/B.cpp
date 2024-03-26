#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int MAX = 1e6 + 7;
int indegree[MAX], outdegree[MAX];
vector<int> edge[MAX];
bool visited[MAX];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    for (auto& it : edges) {
        indegree[it[1]]++;
        outdegree[it[0]]++;
        edge[it[0]].push_back (it[1]);
        visited[it[0]] = true;
        visited[it[1]] = true;
    }
    int start;
    for (int i = 1; i < MAX; i++) {
        if (outdegree[i] >= 2 && indegree[i] == 0) {
            start = i;
            break;
        }
    }
    for (auto& it : edge[start]) {
        indegree[it]--;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i < MAX; i++) {
        if (i == start) continue;
        if (!visited[i]) continue;
        if (indegree[i] == 0) cnt1++;
        if (indegree[i] == 2 && outdegree[i] == 2) cnt2++;
    }
    answer.push_back (start);
    answer.push_back (outdegree[start] - cnt1 - cnt2);
    answer.push_back (cnt1);
    answer.push_back (cnt2);
    return answer;
}
