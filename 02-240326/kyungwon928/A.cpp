#include <iostream>
#include <string>
using namespace std;

string arr[105][105];

string addNum(string n, string m)
{
	string num = "";
	int sum = 0;
	int size = max(n.size(), m.size());

	for (int i = 0; i < size || sum; i++)
	{
		if (n.size() > i)
			sum += n[i] - '0';
		if (m.size() > i)
			sum += m[i] - '0';

		num += (sum % 10) + '0';
		sum /= 10;
	}
	return num;
}

string combination(int n, int m)
{
	if (m == 0 || n == m)
		return "1";

	string &combi = arr[n][m];

	if (combi != "")
		return combi;

	combi = addNum(combination(n - 1, m - 1), combination(n - 1, m));

	return combi;
}

int main()
{
	int n, m;
	cin >> n >> m;

	combination(n, m);

	for (int i = arr[n][m].size() - 1; i >= 0; i--)
	{
		cout << arr[n][m][i];
	}

	return 0;
}