#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s;
  cin >> n >> s;
  vector<int> prefix_sum;
  int sum = 0;
  int min_size = 1000000;
  prefix_sum.push_back(sum);
  for (int i = 0; i < n; i++)
  {
    int input;
    cin >> input;
    sum += input;
    prefix_sum.push_back(sum);
  }
  int idx1 = 0, idx2 = 1;
  while (idx1 <= n)
  {
    if (idx1 == idx2)
      idx2++;
    if (prefix_sum[idx2] - prefix_sum[idx1] >= s)
    {
      if (idx2 - idx1 < min_size)
        min_size = idx2 - idx1;
      idx1++;
    }
    else
    {
      if (idx2 < n)
        idx2++;
      else
        break;
    }
  }
  if (min_size == 1000000)
    min_size = 0;
  cout << min_size << "\n";
  return 0;
}
