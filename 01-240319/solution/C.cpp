#include <string>
#include <vector>

using namespace std;

typedef long long ll;
vector<vector<int>> dices;
int N;
vector<int> diceA, diceB;
vector<int> ans;
vector<int> sumA, sumB;
int dice_check[10], maxVal;

void solve2 (int step, int goal, int cntA, int cntB) {
    if (step == goal) {
        sumA[cntA]++;
        sumB[cntB]++;
        return;
    }
    for (int i = 0; i < 6; i++)
       solve2 (step + 1, goal, cntA + dices[diceA[step]][i], cntB + dices[diceB[step]][i]); 
}

void solve1 (int step, int prev) {
    if (step == N / 2) {
        for (int i = 0; i < N; i++) {
            if (!dice_check[i]) diceB.push_back (i);
        }
        sumA.assign (505, 0);
        sumB.assign (505, 0);
        solve2 (0, N / 2, 0, 0);
        for (int i = 1; i < 505; i++)
            sumB[i] = sumB[i - 1] + sumB[i];
        int tmp = 0;
        for (int i = 1; i < 502; i++) {
            tmp += sumA[i] * sumB[i - 1];
        }
        if (maxVal < tmp) {
            maxVal = tmp;
            ans = diceA;
        }
        vector<int>().swap (diceB);
        return;
    }
    for (int i = prev + 1; i < N; i++) {
        diceA.push_back (i);
        dice_check[i] = true;
        solve1 (step + 1, i);
        diceA.pop_back();
        dice_check[i] = false;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    N = dice.size();
    for (auto& it : dice) dices.push_back (it);
    solve1 (0, -1);
	for (auto& it : ans) answer.push_back (it + 1);
    return answer;
}
