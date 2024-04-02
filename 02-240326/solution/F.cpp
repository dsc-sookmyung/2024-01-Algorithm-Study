#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ans = true;

class TRIE
{
    bool finish;
    TRIE *child[10];
public:
    TRIE()
    {
        finish = false;
        for (int i = 0; i < 10; i++)
            child[i] = NULL;
    }

    ~TRIE()
    {
        for (int i = 0; i < 10; i++)
        {
            if (child[i]) delete child[i];
        }
    }

    void add (string &str, int index)
    {
        if (finish)
            ans = false;
        if (index == str.length())
        {
            finish = true;
            return;
        }
        int cur = str[index] - '0';
        if (!child[cur]) child[cur] = new TRIE();
        child[cur]->add(str, index + 1);
    }

    void find (string &str, int index)
    {
        if (index == str.length())
            return;
        if (finish)
        {
            ans = false;
            return;
        }
        int cur = str[index] - '0';
        if (!child[cur]) return;
        child[cur]->find(str, index + 1);
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans = true;
        vector<string> arr(n);
        TRIE tree;
        while (n--)
        {
            cin >> arr[n];
            if (ans)
                tree.add (arr[n], 0);
        }
        for (auto& it : arr)
            tree.find (it, 0);
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
