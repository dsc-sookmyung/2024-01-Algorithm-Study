#include <iostream>
#include <map>

#define MOD 1000000000000000

using namespace std;

typedef unsigned long long ull;

typedef struct
{
    ull up;
    ull down;
} large;

large recursive(ull m, ull n, map<pair<ull, ull>, large> &arr)
{
    large res;
    res.up = 0;
    res.down = 1;
    if (n == 0 || m == n)
        return res;
    else
    {
        large tmp;
        if (arr.find({m-1,n-1}) == arr.end())
        {
            tmp = recursive(m-1, n-1, arr);
            arr.insert({{m-1,n-1}, tmp});
        }
        if (arr.find({m-1,n}) == arr.end())
        {
            tmp = recursive(m-1, n, arr);
            arr.insert({{m-1,n}, tmp});
        }
        res.down = arr[{m-1,n-1}].down + arr[{m-1,n}].down;
        res.up = arr[{m-1,n-1}].up + arr[{m-1,n}].up;
        res.up += res.down / MOD;
        res.down %= MOD;
        return res;
    }
}

int main(void)
{
    ull m,n;
    map<pair<ull, ull>, large> arr;
    cin>>m>>n;
    large res;
    res = recursive(m, n, arr);
    if (res.up != 0)
        cout<<res.up;
    cout<<res.down<<"\n";
}
