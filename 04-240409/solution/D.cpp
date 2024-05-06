#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x, tmp, cnt;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
      
    }
    sort(v.begin(),v.end());
    cin >> x;
    int st, fn;
    st = 0;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        //cout << v[i] << " ";
    }
    while (st < n) {
        fn = st + 1;
        while (fn != n) {
            if (v[st] + v[fn] > x) {
                break;
            }
            else if (v[st] + v[fn] < x) {
                fn++;
            }
            else {
                cnt++;
                break;
            }
        }
        st++;
    }
    cout << cnt;
}
