#include <string>
#include <vector>

using namespace std;
const int MOD = 10007;

int solution(int n, vector<int> tops) {
    int answer = 0;
    vector<int> a(n, 0), b(n, 0);
    a[0] = 1;
    b[0] = (tops[0] == 0 ? 2 : 3);
    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + b[i - 1];
        a[i] %= MOD;
        if (tops[i] == 0) {
            b[i] = a[i - 1] + 2 * b[i - 1];
            b[i] %= MOD;
        } else {
  			b[i] = 2 * a[i - 1] + 3 * b[i - 1];
            b[i] %= MOD;
        }
    }
    answer = a[n - 1] + b[n - 1];
    answer %= MOD;
    return answer;
}
