#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    while (n > 0) {
        string input;
        int i = 0;
        cin >> input;
        if (input == "push") {
            cin >> i;
            s.push(i);
        }
        else if (input == "top") {
            if (s.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << s.top() << endl;
            }
        }
        else if (input == "size") {
            cout << s.size() << endl;
        }
        else if (input == "pop") {
            if (s.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << s.top() << endl;
                s.pop();
            }
            
        }
        else if (input == "empty") {
            if (s.empty()) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        n--;
    }
}
