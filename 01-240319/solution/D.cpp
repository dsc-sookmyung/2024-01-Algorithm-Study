#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    set<int> a, b;
    for (int i = 0; i < n / 3; i++) a.insert (cards[i]);
    int ptr = n / 3;
    while (true) {
        answer++;
        if (ptr >= n) break;
        b.insert (cards[ptr]);
        b.insert (cards[ptr + 1]);
        ptr += 2;
        bool flag = false;
        // case 1
        for (auto& it : a) {
            if (a.find (n + 1 - it) != a.end()) { // a에 페어가 존재
                flag = true;
                a.erase (it);
                a.erase (n + 1 - it);
                break;
            }
        }
        if (flag) continue;
        // case 2
        for (auto& it : a) {
            if (b.find (n + 1 - it) != b.end()) { // b에 페어가 존재
                flag = true;
                a.erase (it);
                b.erase (n + 1 - it);
                break;
            }
        }
        if (flag && coin > 0) {
            coin--;
            continue;
        }
        // case 3
        for (auto& it : b) {
            if (b.find (n + 1 - it) != b.end()) {
                flag = true;
                b.erase (it);
                b.erase (n + 1 - it);
                break;
            }
        }
        if (flag && coin >= 2) {
            coin -= 2;
            continue;
        }
        break;
    }
    return answer;
}
