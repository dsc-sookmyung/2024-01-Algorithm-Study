#include <string>
#include <vector>

using namespace std;
int cur[55][55], cnt[55], after[55];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0, n = friends.size();
    for (auto& it : gifts) {
        string arr[2] = { "", "" };
        int idx = 0;
        for (auto& c : it) {
            if (c == ' ') {
                idx++;
                continue;
            }
            arr[idx].push_back (c);
        }
        int idx1 = 0, idx2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[0] == friends[i]) idx1 = i;
            if (arr[1] == friends[i]) idx2 = i;
        }
        cur[idx1][idx2]++;
        cnt[idx1]++;
        cnt[idx2]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cur[i][j] > cur[j][i]) {
                after[i]++;
            } else if (cur[i][j] < cur[j][i]) after[j]++;
            else {
                if (cnt[i] > cnt[j]) after[i]++;
                else if (cnt[j] > cnt[i]) after[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) answer = max (answer, after[i]);
    return answer;
}
